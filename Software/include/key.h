#ifndef SOFTWARE_KEY_H
#define SOFTWARE_KEY_H

#include "Arduino.h"

enum PortStatus {
    LLL,
    LLH,
    LHL,
    LHH,
    HLL,
    HLH,
    HHL,
    HHH,
};

enum KeyName {
    KEY1,
    KEY2,
    KEY3,
    KEY4,
    KEY5,
    KEY6,
    KEY7,
    KEY8,
    NONE_KEY
};

class Key {
private:
    uint16_t readPort1;
    uint16_t readPort2;
    uint16_t readPort3;

    uint16_t readPort(uint16_t port);
    PortStatus readPorts();

public:
    Key(uint16_t port1, uint16_t port2, uint16_t port3);
    KeyName getKey();
};





#endif //SOFTWARE_KEY_H
