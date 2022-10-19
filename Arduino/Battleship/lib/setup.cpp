#include <setup.h>

// Class constructor
Setup::Setup(){}

// Class desstructor
Setup::~Setup(){}

// Public Functions
void Setup::Baudrate(int baudrate)
{
    Serial.begin(baudrate);
    Serial.print("Serial.begin(");
    Serial.print(baudrate);
    Serial.println(")");
}
