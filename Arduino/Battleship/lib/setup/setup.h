#include <Arduino.h>

#ifndef Setup_H_
#define Setup_H_

class Setup
{
    public:

    /* Constructeur */
    Setup();

    /* Destructeur */
    ~Setup();

    void Baudrate(int baudrate);

};
#endif