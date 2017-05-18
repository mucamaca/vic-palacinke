/**
 * File s funkcijami za doziranje, merjenje in mesanje mase.
 */


#include <Stepper.h>


Stepper dosing_stepper(80000, DOSING_PUL_PIN, DOSING_DIR_PIN);

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

void disable_heating(){
  digitalWrite(HEATING_PIN_0, 0);
  digitalWrite(HEATING_PIN_1, 0);
}

void heat(){
  if(digitalRead(THERMO_INPUT_0))
    digitalWrite(HEATING_PIN_0,1);
  if(digitalRead(THERMO_INPUT_1))
    digitalWrite(HEATING_PIN_1,1);
  
}

void enable_dosing(){
  disable_heating();
  digitalWrite(DOSING_ENA_PIN,1);
}

void disable_dosing(){
  heat();
  digitalWrite(DOSING_ENA_PIN,0);
}

int nalij(int steps)
{
  enable_dosing();
  int i, mil;
  Serial.println("sajdfs");
  
  while(!Serial.available())
    delay(1);
  Serial.read();
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
  disable_dosing();
  return mil;
}
