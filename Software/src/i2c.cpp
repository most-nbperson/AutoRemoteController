#include "i2c.h"

I2C::I2C(uint16_t scl, uint16_t sda) : sclPin{scl}, sdaPin{sda}
{
    pinMode(this->sdaPin, OUTPUT);
    pinMode(this->sclPin, OUTPUT);
}
const void I2C::sclkClr()
{
    digitalWrite(this->sclPin, LOW);
}

const void I2C::sclkSet()
{
    digitalWrite(this->sclPin, HIGH);
}

const void I2C::sdinClr()
{
    digitalWrite(this->sdaPin, LOW);
}

const void I2C::sdinSet()
{
    digitalWrite(this->sdaPin, HIGH);
}

void I2C::start()
{
    sclkSet();
    sdinSet();
    sdinClr();
    sclkClr();
}

void I2C::stop()
{
    sclkSet();
    sdinClr();
    sdinSet();
}

void I2C::waitAck()
{
    sclkSet();
    sclkClr();
}

void I2C::writeByte(uint8_t data)
{
    unsigned char m,da;
    da = data;

    sclkClr();
    for(int i = 0; i < 8; i++)
    {
        m = da;
        m = m & 0x80;
        if(m == 0x80)
            sdinSet();
        else
            sdinClr();

        da = da << 1;
        sclkSet();
        sclkClr();
    }
}