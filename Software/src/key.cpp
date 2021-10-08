#include "key.h"


Key::Key(uint16_t port1, uint16_t port2, uint16_t port3) :  readPort1{port1}, readPort2{port2}, readPort3{port3}
{
    pinMode(port1, INPUT);
    pinMode(port2, INPUT);
    pinMode(port3, INPUT);
}

uint16_t Key::readPort(uint16_t port)
{
    return digitalRead(port);
}

PortStatus Key::readPorts()
{
    uint8_t portValue1 = readPort(this->readPort1);
    uint8_t portValue2 = readPort(this->readPort2);
    uint8_t portValue3 = readPort(this->readPort3);

    if(portValue3 == LOW && portValue2 == LOW && portValue1 == LOW)
        return LLL;
    if(portValue3 == LOW && portValue2 == LOW && portValue1 == HIGH)
        return LLH;
    if(portValue3 == LOW && portValue2 == HIGH && portValue1 == LOW)
        return LHL;
    if(portValue3 == LOW && portValue2 == HIGH && portValue1 == HIGH)
        return LHH;
    if(portValue3 == HIGH && portValue2 == LOW && portValue1 == LOW)
        return HLL;
    if(portValue3 == HIGH && portValue2 == LOW && portValue1 == HIGH)
        return HLH;
    if(portValue3 == HIGH && portValue2 == HIGH && portValue1 == LOW)
        return HHL;
    if(portValue3 == HIGH && portValue2 == HIGH && portValue1 == HIGH)
        return HHH;

    return LLL;
}

KeyName Key::getKey()
{
    switch (readPorts()) {
        case LLL: return KEY1;
        case LLH: return KEY2;
        case LHL: return KEY3;
        case LHH: return KEY4;
        case HLL: return KEY5;
        case HLH: return KEY6;
        case HHL: return KEY7;
        case HHH: return KEY8;
        default: return NONE_KEY;
    }
}