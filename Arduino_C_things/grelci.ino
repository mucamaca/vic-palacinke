#include "max6675.h"

static MAX6675 thermocouple(THERMO_CLK_PIN, THERMO_CS_PIN, THERMO_DO_PIN);

//TODO dodaj vsega kopijo se za tadrugi grelc.
char grelci_init(){
  pinMode(TERMO_VCC_PIN, OUTPUT);
  pinMode(TERMO_GND_PIN, OUTPUT);  
  digitalWrite(TERMO_VCC_PIN, HIGH);
  digitalWrite(TERMO_GND_PIN, LOW);
  pinMode(GRELEC_SPODNJI, OUTPUT);
  pinMode(GRELEC_ZGORNJI, OUTPUT);
  delay(1200);
  if(thermocouple.readCelsius() == nan)
    return 84; //some not yet defined errorcode
  else
    return 0;
}

// med dvema klicema te funkcije mora bit vsaj 900ms
char grelci() {
  int t = (int)thermocouple.readCelsius();
  Serial.println(t);
  if(t > TARGET_TEMP)
    digitalWrite(SPODNJI_GRELEC, 0);
  else
    digitalWrite(SPODNJI_GRELEC,1);
}
