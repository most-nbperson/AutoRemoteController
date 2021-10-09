#ifndef SOFTWARE_IR_H
#define SOFTWARE_IR_H

#include <Arduino.h>
#include <IRsend.h>
#include <IRrecv.h>
#include <IRremoteESP8266.h>
#include <IRutils.h>

class IR {
private:
    uint16_t irRecvPin;
    uint16_t irTransPin;
    uint16_t irCaptureBufferSize;
    uint8_t irTimeout;  //ms
    uint16_t irFrequency;  //38kHz

    uint16_t* reciveData;
    uint16_t reciveDataLength;

    IRsend* irSend;
    IRrecv* irRecv;

public:
    IR(uint16_t recv, uint16_t trans, uint16_t captureBuff, uint8_t timeout, uint16_t frequency);
    int irRecive();
    void irTransmit(uint16_t* sendData, uint16_t len);
    uint16_t getReciveDataLength(void);
    void getReciveData(uint16_t* getData, uint16_t len);

};

#endif //SOFTWARE_IR_H
