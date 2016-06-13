/**
 * File s funkcijami za doziranje, merjenje in mesanje mase.
 */

#include <Stepper.h>

static Stepper dosing_stepper(1600, DOSING_PUL_PIN, DOSING_DIR_PIN);

void blob(){
  dosing_stepper.step(-600);
}

void meow(){
  dosing_stepper.step(600);
}

char masa_init(){
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(2), blob, FALLING);
  attachInterrupt(digitalPinToInterrupt(3), meow, RISING);
  dosing_stepper.setSpeed(200);
  char masa=check_masa();
  return masa?masa:init_ultrasonic();
}

char check_masa(){
  return 0;
}

char init_ultrasonic(){
  return 0;
}



void dispense_pancake(){
  static char pancake_index=0;
  pancake_index= pancake_index%2;
  pancake[pancake_index++] = all_steps;
  blob();
  delay(MASA_PER_PANCAKE * 1000);
  meow();
}

