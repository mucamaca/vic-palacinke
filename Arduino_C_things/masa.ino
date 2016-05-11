/**
 * File s funkcijami za doziranje, merjenje in mesanje mase.
 */

#include <Stepper.h>

static Stepper dosing_stepper(1600, DOSING_STEPPER_PUL_PIN, DOSING_STEPPER_DIR_PIN);

char check_masa(){
  return 0;
}

void dispense_pancake(){
  static char pancake_index = 0;
//  pancake[pancake_index++] = steps;
  //TODO
}

