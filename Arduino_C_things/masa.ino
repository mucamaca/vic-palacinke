/**
 * File s funkcijami za doziranje, merjenje in mesanje mase.
 */

#include <Stepper.h>

static Stepper dosing_stepper(1600, DOSING_PUL_PIN, DOSING_DIR_PIN);

void blob(){
  dosing_stepper.step(600);
}

void meow(){
  dosing_stepper.step(-600);
}

void mow(){
  trak_moving = !trak_moving;
}

char masa_init(){
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(2), blob, FALLING);
  attachInterrupt(digitalPinToInterrupt(3), mow, RISING);
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


void dispense_pancake();

