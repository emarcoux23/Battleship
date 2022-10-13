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

    /* Fonction pour initialiser l'electroaimant*/
    void Setup::Baudrate(int baudrate);

};
#endif