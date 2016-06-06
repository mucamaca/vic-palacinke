/**
 * File s funkcijami za doziranje, merjenje in mesanje mase.
 */

#include <Stepper.h>

static Stepper dosing_stepper(1600, DOSING_PUL_PIN, DOSING_DIR_PIN);

char masa_init(){
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
  pancake_index=1-pancake_index;
  pancake[pancake_index++] = all_steps;
  dosing_stepper.step(80);
  delay(MASA_PER_PANCAKE * 1000);
  dosing_stepper.step(-80);
}

