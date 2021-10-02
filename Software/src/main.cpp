#include <Arduino.h>

void setup() {
// write your initialization code here
    Serial.begin(115200);
}

void loop() {
// write your code here
    Serial.printf("hello world");
    delay(100);
}