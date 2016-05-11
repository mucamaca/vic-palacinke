/**
 * File s funkcijami za upravljanje grelcev in pecenje. 
 */

#include <max6675.h>


static MAX6675 spodnji_thermocouple(SPODNJI_THERMO_CLK, SPODNJI_THERMO_CS, SPODNJI_THERMO_DO);
static MAX6675 zgornji_thermocouple(ZGORNJI_THERMO_CLK, ZGORNJI_THERMO_CS, ZGORNJI_THERMO_DO);

char grelci_init(){
  pinMode(SPODNJI_THERMO_VCC, OUTPUT);
  pinMode(SPODNJI_THERMO_GND, OUTPUT);  
  digitalWrite(SPODNJI_THERMO_VCC, HIGH);
  digitalWrite(SPODNJI_THERMO_GND, LOW);
  
  pinMode(ZGORNJI_THERMO_VCC, OUTPUT);
  pinMode(ZGORNJI_THERMO_GND, OUTPUT);  
  digitalWrite(ZGORNJI_THERMO_VCC, HIGH);
  digitalWrite(ZGORNJI_THERMO_GND, LOW);
  
  pinMode(SPODNJI_GRELEC, OUTPUT);
  pinMode(ZGORNJI_GRELEC, OUTPUT);
  
  delay(1000);
 /* if(spodnji_thermocouple.readCelsius() == ) //|| zgornji_thermocouple.readCelsius() == nan)
    return 84; //some not yet defined errorcode
  else
    return 0;
    */
}

void grelci(){
  int t_spodnji = (int)spodnji_thermocouple.readCelsius();
  int t_zgornji = (int)zgornji_thermocouple.readCelsius();

  if(t_spodnji > TARGET_TEMP)
    digitalWrite(SPODNJI_GRELEC, 0);
  else
    digitalWrite(SPODNJI_GRELEC, 1);
    
  if(t_zgornji > TARGET_TEMP)
    digitalWrite(ZGORNJI_GRELEC, 0);
  else
    digitalWrite(ZGORNJI_GRELEC, 1);
  return 0;
}

void bake(){
  is_baking = 1;
}


