#include "ir.h"

IR::IR(uint16_t recv, uint16_t trans, uint16_t captureBuff, uint8_t timeout, uint16_t frequency) :
        irRecvPin{recv}, irTransPin{trans}, irCaptureBufferSize{captureBuff}, irTimeout{timeout}, irFrequency{frequency}
{
    irsend = new IRsend{this->irTransPin};
    irrecv = new IRrecv{this->irRecvPin};
    irrecv->enableIRIn();
    irsend->begin();
}

int IR::irRecive(uint16_t* getData)
{
    decode_results results;
    if(irrecv->decode(&results)) {
        getData = resultToRawArray(&results);
        int length = getCorrectedRawLength(&results);
        irrecv->resume();
        return length;
    }
    else
        return -1;
}

void IR::irTransmit(uint16_t* sendData, uint16_t len)
{
    irsend->sendRaw(sendData, len, this->irFrequency);
}
