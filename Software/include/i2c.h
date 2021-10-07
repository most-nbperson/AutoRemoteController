#ifndef SOFTWARE_I2C_H
#define SOFTWARE_I2C_H

#include "Arduino.h"

class I2C {
private:
    unsigned char sclPin;
    unsigned char sdaPin;

    const void sclkClr();
    const void sclkSet();
    const void sdinClr();
    const void sdinSet();
public:
    I2C(unsigned char scl, unsigned char sda);
    void start();
    void stop();
    void waitAck();
    void writeByte(unsigned char data);
};

#endif //SOFTWARE_I2C_H
