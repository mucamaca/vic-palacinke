/**
 * Koda je napisana za attiny85
 */

#include <Stepper.h>

Stepper stepper(400, 2, 1);

void setup() {
  pinMode(0,INPUT);
}

void loop() {
  if(!digitalRead(0))
    stepper.step(-3);
  else
    delay(100);
}
