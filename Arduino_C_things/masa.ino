/**
 * File s funkcijami za doziranje, merjenje in mesanje mase.
 */


#include <Stepper.h>


static Stepper dosing_stepper(80000, DOSING_PUL_PIN, DOSING_DIR_PIN);


void masa_init(void)
{
  //dosing_stepper.setSpeed(2);
  //pinMode(DOSING_ENA_PIN, OUTPUT);
}

void move(int meow)
{
  int i;
  //digitalWrite(DOSING_ENA_PIN,1);
  for(i=0;i<meow/2;i++){
    dosing_stepper.step(2);
    delay(1);
  }
  delay(800);
  for(i=0;i<meow/2;i++){
    dosing_stepper.step(-2);
    delay(1);
  }
}
