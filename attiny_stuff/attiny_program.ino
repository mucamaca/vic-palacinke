/*
 * Koda je napisana za attiny85
 */

#include <Stepper.h>

Stepper stepper(1600, 0, 1);

void setup() {
  pinMode(2,INPUT);
  stepper.setSpeed(100);
}

void loop() {
  if(digitalRead(2))
    stepper.step(100);
}
