/**
 * Koda je napisana za attiny85
 */

#include <Stepper.h>
#define FROM_ARDUINO_PIN 0
#define STEPPER_PUL 2
#define STEPPER_DIR 1

Stepper stepper(400, STEPPER_PUL, STEPPER_DIR);

bool last_read = true;

void setup() {
  pinMode(FROM_ARDUINO_PIN, INPUT);
}

void loop() {
  bool rd = digitalRead(FROM_ARDUINO_PIN);
  if(rd){
    if(rd == last_read){
      stepper.step(5);  
    }else{
      delay(50);
      last_read = rd;
    }
    
  }else{
    if(rd == last_read){
      stepper.step(-5);  
    }else{
      delay(50);
      last_read = rd;
    }
  }
}
