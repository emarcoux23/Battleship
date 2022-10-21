#include <Arduino.h>

#ifndef Led_H_
#define Led_H_

class Led
{
    public:

    /* Constructeur */
    Led();

    /* Destructeur */
    ~Led();

    void Off();
    void Blue();
    void Green();
    void Red();
    void White();

    private:

    int blueLed = 2;
    int greenLed = 3;
    int redLed = 4;
    int whiteLed = 5;
};
#endif