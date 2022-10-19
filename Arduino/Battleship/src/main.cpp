#include <Arduino.h>
#include <ArduinoJson.h>
#include "setup.h"

#define BAUDRATE 9600

bool trigger       = false;

bool shouldSend    = false;
bool shouldRead    = false;
float yolo         = 0;

void sendMsg();
void readMsg();

void setup() 
{
  Setup setup;
  setup.Baudrate(BAUDRATE);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() 
{
  shouldRead = true;
  shouldSend = true;

  if (shouldSend == true)
    sendMsg();
  if (shouldRead == true)
    readMsg();

  if (yolo == 2.3)
    digitalWrite(LED_BUILTIN, HIGH);
  else
    digitalWrite(LED_BUILTIN, LOW);

  delay(100);
}

void sendMsg()
{
  StaticJsonDocument<500> doc;

  doc["time_ms"] = millis();
  doc["time_sec"] = millis()/1000;
  doc["time_min"] = millis()/1000/60;

  serializeJson(doc, Serial);
  Serial.println();

  shouldSend = false;
}

void readMsg()
{
  StaticJsonDocument<500> doc;
  JsonVariant parse_msg;
  DeserializationError error = deserializeJson(doc, Serial);
  shouldRead = false;

  if (error) 
  {
    Serial.print("deserialize() failed: ");
    Serial.println(error.c_str());
    return;
  }
  
  parse_msg = doc["yolo"];
  if (!parse_msg.isNull())
  {
     yolo = doc["yolo"].as<float>();
  }
}
