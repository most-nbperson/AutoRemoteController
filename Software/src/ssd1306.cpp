#include "ssd1306.h"

SSD1306::SSD1306(uint16_t sda, uint16_t scl)
{
    i2cDev = new I2C{scl, sda};
    
    writeByte(0xAE,OLED_CMD);//--display off
    writeByte(0x00,OLED_CMD);//---set low column address
    writeByte(0x10,OLED_CMD);//---set high column address
    writeByte(0x40,OLED_CMD);//--set start line address  
    writeByte(0xB0,OLED_CMD);//--set page address
    writeByte(0x81,OLED_CMD); // contract control
    writeByte(0xFF,OLED_CMD);//--128   
    writeByte(0xA1,OLED_CMD);//set segment remap 
    writeByte(0xA6,OLED_CMD);//--normal / reverse
    writeByte(0xA8,OLED_CMD);//--set multiplex ratio(1 to 64)
    writeByte(0x3F,OLED_CMD);//--1/32 duty
    writeByte(0xC8,OLED_CMD);//Com scan direction
    writeByte(0xD3,OLED_CMD);//-set display offset
    writeByte(0x00,OLED_CMD);//

    writeByte(0xD5,OLED_CMD);//set osc division
    writeByte(0x80,OLED_CMD);//

    writeByte(0xD8,OLED_CMD);//set area color mode off
    writeByte(0x05,OLED_CMD);//

    writeByte(0xD9,OLED_CMD);//Set Pre-Charge Period
    writeByte(0xF1,OLED_CMD);//

    writeByte(0xDA,OLED_CMD);//set com pin configuartion
    writeByte(0x12,OLED_CMD);//

    writeByte(0xDB,OLED_CMD);//set Vcomh
    writeByte(0x30,OLED_CMD);//

    writeByte(0x8D,OLED_CMD);//set charge pump enable
    writeByte(0x14,OLED_CMD);//

    writeByte(0xAF,OLED_CMD);//--turn on oled panel
}

SSD1306::~SSD1306()
{
    delete i2cDev;
}

void SSD1306::writeCommand(uint8_t cmd)
{
    i2cDev->start();
    i2cDev->writeByte(0x78);  //Slave address,SA0=0
    i2cDev->waitAck();
    i2cDev->writeByte(0x00);  //write command
    i2cDev->waitAck();
    i2cDev->writeByte(cmd);
    i2cDev->waitAck();
    i2cDev->stop();
}

void SSD1306::writeData(uint8_t data)
{
    i2cDev->start();
    i2cDev->writeByte(0x78);
    i2cDev->waitAck();
    i2cDev->writeByte(0x40);
    i2cDev->waitAck();
    i2cDev->writeByte(data);
    i2cDev->waitAck();
    i2cDev->stop();
}

void SSD1306::writeByte(uint8_t dat, uint8_t flag)
{
    if(flag)
        writeData(dat);
    else
        writeCommand(dat);
}

void SSD1306::displayOn()
{
    writeByte(0X8D,OLED_CMD);  //SET DCDC命令
    writeByte(0X14,OLED_CMD);  //DCDC ON
    writeByte(0XAF,OLED_CMD);  //DISPLAY ON
}

void SSD1306::displayOff()
{
    writeByte(0X8D, OLED_CMD);  //SET DCDC命令
    writeByte(0X10, OLED_CMD);  //DCDC OFF
    writeByte(0XAE, OLED_CMD);  //DISPLAY OFF
}

void SSD1306::displayClear(uint8_t dat)
{
    for(int i = 0; i < 8; i++)
    {
        writeByte (0xb0 + i, OLED_CMD);    //设置页地址（0~7）
        writeByte (0x00, OLED_CMD);      //设置显示位置—列低地址
        writeByte (0x10, OLED_CMD);      //设置显示位置—列高地址
        for(int j = 0; j < 128; j++)
            writeByte(0, OLED_DATA);
    } //更新显示
}

void SSD1306::setPos(uint8_t x, uint8_t y)
{
    writeByte(0xb0 + y, OLED_CMD);
    writeByte(((x & 0xf0) >> 4) | 0x10, OLED_CMD);
    writeByte((x & 0x0f), OLED_CMD);
}

void SSD1306::showChar(uint8_t x, uint8_t y, uint8_t chr, uint8_t charSize)
{
    unsigned char c = 0;
    c = chr - ' ';//得到偏移后的值

    if(x > Max_Column - 1)
    {
        x = 0;
        y = y + 2;
    }

    if(charSize ==16)
    {
        setPos(x, y);
        for(int i = 0; i < 8; i++)
            writeByte(F8X16[c*16+i], OLED_DATA);
        setPos(x, y+1);
        for(int i = 0; i < 8; i++)
            writeByte(F8X16[c*16+i+8], OLED_DATA);
    }
    else {
        setPos(x, y);
        for(int i = 0; i < 6; i++)
            writeByte(F6x8[c][i], OLED_DATA);
    }
}

void SSD1306::showString(uint8_t x, uint8_t y, uint8_t*p, uint8_t charSize)
{
    unsigned char i = 0;
    while (p[i] != '\0')
    {
        showChar(x, y, p[i], charSize);
        x += 8;
        if(x > 120)
        {
            x = 0;
            y += 2;
        }
        i++;
    }
}