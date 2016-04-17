#include "max6675.h"

MAX6675 thermocouple(THERMO_CLK_PIN, THERMO_CS_PIN, THERMO_DO_PIN);
  
char grelci_setup(){
  pinMode(TERMO_VCC_PIN, OUTPUT);
  pinMode(TERMO_GND_PIN, OUTPUT);  
  digitalWrite(TERMO_VCC_PIN, HIGH);
  digitalWrite(TERMO_GND_PIN, LOW);
  pinMode(GRELEC_SPODNJI,OUTPUT);
  pinMode(GRELEC_ZGORNJI,OUTPUT);
  delay(1200);
  if(thermocouple.readCelsius()==nan)
    return 84; //some not yet defined errorcode
  else
    return 0;
}
// med dvema klicema te funkcije mora bit vsaj 800ms
char grelci() {
  int t;
  t=(int)thermocouple.readCelsius();
  Serial.println(t);
  if(t>80)
    digitalWrite(6,0);
  else
    digitalWrite(6,1);
}
