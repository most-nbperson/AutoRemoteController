#include <Arduino.h>

#include "key.h"
#include "i2c.h"
#include "ssd1306.h"
#include "ir_Gree.h"
#include "ir_Kelvinator.h"

SSD1306 oled{13, 12};
Key key{16, 2, 4};

void setup() {
// write your initialization code here
    Serial.begin(115200);
}

void loop() {
// write your code here
//    Serial.printf("hello world\n");
//    oled.showString(0, 0, (unsigned char *) "hello", 8);
//    if(key.getKey() == KEY1)
//        oled.showString(0, 9, (unsigned char *) "KEY1", 8);
//    delay(100);
}