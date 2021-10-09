#include "ir.h"

IR::IR(uint16_t recv, uint16_t trans, uint16_t captureBuff, uint8_t timeout, uint16_t frequency) :
        irRecvPin{recv}, irTransPin{trans}, irCaptureBufferSize{captureBuff}, irTimeout{timeout}, irFrequency{frequency}
{
    irSend = new IRsend{this->irTransPin};
    irRecv = new IRrecv{this->irRecvPin};
    irRecv->enableIRIn();
    irSend->begin();
}

int IR::irRecive()
{
    decode_results results;
    if(irRecv->decode(&results))
    {
        reciveData = resultToRawArray(&results);
        reciveDataLength = getCorrectedRawLength(&results);
        irRecv->resume();
        return 0;
    }
    else
        return -1;
}

void IR::irTransmit(uint16_t* sendData, uint16_t len)
{
    irSend->sendRaw(sendData, len, this->irFrequency);
}

uint16_t IR::getReciveDataLength(void)
{
    return reciveDataLength;
}

void IR::getReciveData(uint16_t* getData, uint16_t len)
{
    for (int i = 0; i < len; ++i)
        *(getData+i) = *(reciveData+i);
}