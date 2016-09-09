/*
 * Koda je napisana za attiny85
 */

#include <Stepper.h>
#define FROM_ARDUINO_PIN 0
#define STEPPER_PUL 2
#define STEPPER_DIR 1

Stepper stepper(400, STEPPER_PUL, STEPPER_DIR);

void setup() {
  pinMode(FROM_ARDUINO_PIN, INPUT);
}

void loop() {
  if(digitalRead(FROM_ARDUINO_PIN))
    stepper.step(5);
  else
    stepper.step(-5);
}
