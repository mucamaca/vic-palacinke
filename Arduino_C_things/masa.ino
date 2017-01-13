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

int nalij(int steps)
{
  int i, mil;
#ifdef DBG
  
  /*while(!Serial.available())
    delay(1);
  Serial.read();*/
#endif
  //digitalWrite(DOSING_ENA_PIN,1);
  for(i=0;i<steps/2;i++){
    dosing_stepper.step(-2);
    delay(1);
  }
#ifdef DBG
  mil=millis();
  while(!Serial.available())
    delay(1);
  mil=millis()-mil;
  Serial.read();
#else
  delay(DOZIRANJE_CAJT * 1000);
  mil=DOZIRANJE_CAJT * 1000;
#endif  
  for(i=0;i<steps/2;i++){
    dosing_stepper.step(2);
    delay(1);
  }
  return mil;
}
