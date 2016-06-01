/*
 * Koda je napisana za attiny85
 */

#include <Stepper.h>

Stepper stepper(400, 1, 0);

void setup() {
  pinMode(2,INPUT);
}

void loop() {
  if(digitalRead(2))
    stepper.step(5);
}
