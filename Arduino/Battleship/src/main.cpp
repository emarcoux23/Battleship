#include <Arduino.h>
#include <ArduinoJson.h>
#include "setup.h"
#include "led.h"

#define BAUDRATE   9600

Setup set;
Led led;

enum SEQUENCE_STEP {STEP_STALL,
                    STEP_BLUE,
                    STEP_GREEN, 
                    STEP_RED, 
                    STEP_WHITE};
SEQUENCE_STEP STEP;   

bool shouldSend = false;
bool shouldRead = false;

bool ask_user_input = false;
int msg_step = STEP_STALL;
String msg_blue = "";

unsigned long temps = 0;

void sendMsg();
void readMsg();

void setup() 
{
  set.Baudrate(BAUDRATE);
  STEP = STEP_STALL;
}

void loop() 
{
  switch (STEP)
  {

  case STEP_STALL:
    led.Off();
    ask_user_input = true;
    shouldRead = true;
    shouldSend = true;
    temps = millis();
    break;

  case STEP_BLUE:
    led.Blue();
    ask_user_input = false;
    shouldRead = false;
    shouldSend = true;

    msg_blue = "Allo ici bleu";

    if (millis() - temps > 2000)
      STEP = STEP_STALL;
    break;

  case STEP_GREEN:
    led.Green();
    ask_user_input = false;
    shouldRead = false;
    shouldSend = true;

    msg_blue = "Allo ici vert";

    if (millis() - temps > 2000)
      STEP = STEP_RED;
    break;

  case STEP_RED:
    led.Red();
    ask_user_input = true;
    shouldRead = true;
    shouldSend = true;
    break;

  case STEP_WHITE:
    led.White();
    ask_user_input = true;
    shouldRead = true;
    shouldSend = true;
    break;
  
  default:
    break;
  }

  if (shouldSend == true)
    sendMsg();
  if (shouldRead == true)
    readMsg();

  //delay(100);
}

void sendMsg()
{
  StaticJsonDocument<500> doc;

  doc["time_ms"] = millis();
  doc["msg_blue"] = msg_blue;
  doc["ask_user_input"] = ask_user_input;

  serializeJson(doc, Serial);
  Serial.println();

  shouldSend = false;
}

void readMsg()
{
  StaticJsonDocument<500> doc;
  JsonVariant parse_msg;
  DeserializationError error = deserializeJson(doc, Serial);
  //shouldRead = false;

  if (error) 
  {
    Serial.print("deserialize() failed: ");
    Serial.println(error.c_str());
    return;
  }
  
  parse_msg = doc["msg_step"];
  if (!parse_msg.isNull())
  {
     msg_step = doc["msg_step"].as<int>();
     STEP = static_cast<SEQUENCE_STEP>(msg_step);
  }
}
