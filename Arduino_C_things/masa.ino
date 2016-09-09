/**
 * File s funkcijami za doziranje, merjenje in mesanje mase.
 */


#include <Stepper.h>


static Stepper dosing_stepper(80000, DOSING_PUL_PIN, DOSING_DIR_PIN);


char check_masa(void)
{
  return 1;
}


bool init_ultrasonic(void)
{
  return 1;
}


void masa_init(void)
{
  dosing_stepper.setSpeed(2);
  pinMode(DOSING_ENA_PIN, OUTPUT);
  if(!init_ultrasonic())
    *error_bit_mask |= ULTRASONIC_ERROR;
  else if(!check_masa())
    *error_bit_mask |= MASA_ERROR; 
}

void stupid(void)
{
  int i;
  digitalWrite(DOSING_ENA_PIN,1);
  for(i=0;i<200;i++){
    dosing_stepper.step(2);
    delay(1);
  }
  delay(800);
  for(i=0;i<200;i++){
    dosing_stepper.step(-2);
    delay(1);
  }
}
