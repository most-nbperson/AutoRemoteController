#include <Arduino.h>

#include "key.h"
#include "i2c.h"
#include "ssd1306.h"

SSD1306 oled{13, 12};

void setup() {
// write your initialization code here
    Serial.begin(115200);
//    keyInit();
}

void loop() {
// write your code here
    Serial.printf("hello world\n");
    oled.showString(0, 0, (unsigned char *) "hello", 8);
    delay(100);
}