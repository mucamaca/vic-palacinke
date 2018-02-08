/**
 * File s funkcijami za doziranje, merjenje in mesanje mase.
 */


#include <Stepper.h>


Stepper dosing_stepper(80000, DOSING_PUL_PIN, DOSING_DIR_PIN);

void dosing_enable(){
  digitalWrite(DOSING_ENA_PIN,1);
}

void dosing_disable(){
  digitalWrite(DOSING_ENA_PIN,0);
}

void dosing_setup(){
  pinMode(DOSING_ENA_PIN, OUTPUT);
  dosing_disable();
}

int nalij(int steps)
{
  
  int i, mil;
  
  while(!Serial.available())
    delay(1);
  if(Serial.read()=='~'){
    Serial.print(",nmskfhjasdf");
    return 0;
  }
  dosing_enable();
  for(i=0;i<steps/2;i++){
    dosing_stepper.step(-2);
    delay(1);
  }
  mil=millis();
  while(!Serial.available())
    delay(1);
  mil=millis()-mil;
  Serial.read();
  
  for(i=0;i<steps/2;i++){
    dosing_stepper.step(2);
    delay(1);
  }
  delay(50);
  dosing_disable();
  return mil;
}
