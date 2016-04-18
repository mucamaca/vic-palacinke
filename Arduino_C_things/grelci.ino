/* 
 * File s funkcijami za uravnavanje temperature grelcev. 
 * 
 */

#include "max6675.h"


static MAX6675 spodnji_thermocouple(SPODNJI_THERMO_CLK, SPODNJI_THERMO_CS, SPODNJI_THERMO_DO);
static MAX6675 zgornji_thermocouple(ZGORNJI_THERMO_CLK, ZGORNJI_THERMO_CS, ZGORNJI_THERMO_DO);

//TODO dodaj vsega kopijo se za tadrugi grelc.
char grelci_init(){
  pinMode(SPODNJI_TERMO_VCC, OUTPUT);
  pinMode(SPODNJI_TERMO_GND, OUTPUT);  
  digitalWrite(SPODNJI_TERMO_VCC, HIGH);
  digitalWrite(SPODNJI_TERMO_GND, LOW);
  
  pinMode(ZGORNJI_TERMO_VCC, OUTPUT);
  pinMode(ZGORNJI_TERMO_GND, OUTPUT);  
  digitalWrite(ZGORNJI_TERMO_VCC, HIGH);
  digitalWrite(ZGORNJI_TERMO_GND, LOW);
  
  pinMode(GRELEC_SPODNJI, OUTPUT);
  pinMode(GRELEC_ZGORNJI, OUTPUT);
  
  delay(1000);
  if(spodnji_thermocouple.readCelsius() == nan || zgornji_thermocouple.readCelsius() == nan)
    return 84; //some not yet defined errorcode
  else
    return 0;
}

// med dvema klicema te funkcije mora bit vsaj 900ms
char grelci(){
  int t_spodnji = (int)spodnji_thermocouple.readCelsius();
  int t_zgornji = (int)zgornji_thermocouple.readCelsius();
  
  if(t_spodnji > TARGET_TEMP)
    digitalWrite(SPODNJI_GRELEC, 0);
  else
    digitalWrite(SPODNJI_GRELEC,1);
    
  if(t_zgornji > TARGET_TEMP)
    digitalWrite(ZGORNJI_GRELEC, 0);
  else
    digitalWrite(ZGORNJI_GRELEC,1);
  return 0;
}
