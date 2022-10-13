#include <Arduino.h>
#include "setup.h"

#define BAUDRATE 9600

bool trigger = false;

void setup() 
{
  Setup setup;
  setup.Baudrate(BAUDRATE);

  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() 
{
  if (Serial.available() > 0)
  {
    String msg = Serial.readString();

    if (msg == "ON")
    {
      trigger = true;
    }
    else
      trigger = false;
  }

  if (trigger)
  {
    digitalWrite(LED_BUILTIN, HIGH);
    delay(500);
    digitalWrite(LED_BUILTIN, LOW);
    delay(500);
  }
  else
    digitalWrite(LED_BUILTIN, LOW);

  Serial.println("test");
}
