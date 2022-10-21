#include <led.h>

// Class constructor
Led::Led()
{
    pinMode(blueLed, OUTPUT);
    pinMode(greenLed, OUTPUT);
    pinMode(redLed, OUTPUT);
    pinMode(whiteLed, OUTPUT);
}

// Class desstructor
Led::~Led(){}

// Public Functions
void Led::Off()
{
    digitalWrite(blueLed,   LOW);
    digitalWrite(greenLed,  LOW);
    digitalWrite(redLed,    LOW);
    digitalWrite(whiteLed,  LOW);
}

void Led::Blue()
{
    digitalWrite(blueLed,   HIGH);
    digitalWrite(greenLed,  LOW);
    digitalWrite(redLed,    LOW);
    digitalWrite(whiteLed,  LOW);
}

void Led::Green()
{
    digitalWrite(blueLed,   LOW);
    digitalWrite(greenLed,  HIGH);
    digitalWrite(redLed,    LOW);
    digitalWrite(whiteLed,  LOW);
}

void Led::Red()
{
    digitalWrite(blueLed,   LOW);
    digitalWrite(greenLed,  LOW);
    digitalWrite(redLed,    HIGH);
    digitalWrite(whiteLed,  LOW);
}

void Led::White()
{
    digitalWrite(blueLed,   LOW);
    digitalWrite(greenLed,  LOW);
    digitalWrite(redLed,    LOW);
    digitalWrite(whiteLed,  HIGH);
}