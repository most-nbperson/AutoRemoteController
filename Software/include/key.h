#ifndef SOFTWARE_KEY_H
#define SOFTWARE_KEY_H

#include "Arduino.h"

class Key {
private:
    enum KeyReadPort
    {
        PORT_0 = 16,
        PORT_1 = 2,
        PORT_2 = 4,
    };

    enum KeyName
    {
        KEY1,
        KEY2,
        KEY3,
        KEY4,
        KEY5,
        KEY6,
        KEY7,
        KEY8,
    };

public:
    Key();

};





#endif //SOFTWARE_KEY_H
