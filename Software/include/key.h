#ifndef SOFTWARE_KEY_H
#define SOFTWARE_KEY_H

#include "Arduino.h"

void keyInit();
enum EncoderValue ketGetEncoderValue();

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

enum EncoderValue
{
    __000,
    __001,
    __010,
    __011,
    __100,
    __101,
    __110,
    __111,
};

#endif //SOFTWARE_KEY_H
