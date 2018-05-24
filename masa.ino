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
  delay(200);
  
  dosing_disable();
  Serial.println("mhaahhahhaha");
  while(!Serial.available()) delay(1);
  Serial.read();
  dosing_enable();
  Serial.println("meiwooeu");
  for(int i=0;i<(DOZIRANJE_START+DOZIRANJE_STEP)/2;i++){
    dosing_stepper.step(-2);
    delay(1);
  }
}

int nalij(int steps)
{
  
  int i, mil;
  delay(100);
  for(i=0;i<steps/2;i++){
    dosing_stepper.step(2);
    delay(1);
  }
  delay(8000);
  for(i=0;i<steps/2;i++){
    dosing_stepper.step(-2);
    delay(1);
  }
  delay(50);

  return mil;
}
