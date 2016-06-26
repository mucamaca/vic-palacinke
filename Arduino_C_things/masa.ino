/**
 * File s funkcijami za doziranje, merjenje in mesanje mase.
 */


#include <Stepper.h>


static Stepper dosing_stepper(1600, DOSING_PUL_PIN, DOSING_DIR_PIN);


void masa_init()
{
  dosing_stepper.setSpeed(200);
  if(!init_ultarsonic())
    *error_bit_mask |= ULTRASONIC_ERROR;
  else if(!check_masa)
    *error_bit_mask |= MASA_ERROR; 
}


char check_masa()
{
  return 1;
}


bool init_ultrasonic()
{
  return 1;
}
