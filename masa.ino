/**
 * File s funkcijami za doziranje, merjenje in mesanje mase.
 */


#include <Stepper.h>


static Stepper dosing_stepper(80000, DOSING_PUL_PIN, DOSING_DIR_PIN);

int t_ime(){
  int mil;
  while(!Serial.available())
    delay(1);
  Serial.read();
  mil=millis();
  while(!Serial.available())
    delay(1);
  mil=millis()-mil;
  Serial.read();
  return mil;
}

void calibrate(){
  int t, v;
  t=t_ime();
//  v=parse_volume();
  //do_some_stuff
}

void enable_dosing(){
  digitalWrite(DOSING_ENA_PIN,1);
}

void disable_dosing(){
  digitalWrite(DOSING_ENA_PIN,0);
}

int nalij(int steps)
{
  enable_dosing();
  int i, mil;
#ifdef DBG
  
  while(!Serial.available())
    delay(1);
  Serial.read();
#endif
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
  delay(50);
  disable_dosing();
  return mil;
}
