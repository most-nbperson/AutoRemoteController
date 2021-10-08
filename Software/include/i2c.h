#ifndef SOFTWARE_I2C_H
#define SOFTWARE_I2C_H

#include "Arduino.h"

class I2C {
private:
    uint16_t sclPin;
    uint16_t sdaPin;

    const void sclkClr();
    const void sclkSet();
    const void sdinClr();
    const void sdinSet();
public:
    I2C(uint16_t scl, uint16_t sda);
    void start();
    void stop();
    void waitAck();
    void writeByte(uint8_t data);
};

#endif //SOFTWARE_I2C_H
