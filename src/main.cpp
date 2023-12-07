#include <Arduino.h>
#include <key_practice.h>

#define KEY_PRACTICE (1)


void setup() {
  Serial.begin(9600, SERIAL_8N1);

#if KEY_PRACTICE
  key_practice_setup();
#endif
}

void loop() {
#if KEY_PRACTICE
  key_practice_loop();
#endif
}