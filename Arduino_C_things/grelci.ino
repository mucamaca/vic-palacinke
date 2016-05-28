/**
 * File s funkcijami za upravljanje grelcev in pecenje. 
 */

#include <max6675.h>


static MAX6675 spodnji_thermocouple(SPODNJI_THERMO_CLK, SPODNJI_THERMO_CS, SPODNJI_THERMO_DO);
static MAX6675 zgornji_thermocouple(ZGORNJI_THERMO_CLK, ZGORNJI_THERMO_CS, ZGORNJI_THERMO_DO);

char grelci_init(){
  pinMode(SPODNJI_GRELEC, OUTPUT);
  pinMode(ZGORNJI_GRELEC, OUTPUT);

  digitalWrite(ZGORNJI_GRELEC, 1);
  digitalWrite(SPODNJI_GRELEC, 1);
    
  delay(1000);
  
  if(spodnji_thermocouple.readCelsius() == 0 || zgornji_thermocouple.readCelsius() == 0)
    return 84; //some not yet defined errorcode
  else
    return 0;
}

void check_grelci(){
  if((int)spodnji_thermocouple.readCelsius() > TARGET_TEMP)
    digitalWrite(SPODNJI_GRELEC, 0);
  else
    digitalWrite(SPODNJI_GRELEC, 1);
    
  if((int)zgornji_thermocouple.readCelsius() > TARGET_TEMP)
    digitalWrite(ZGORNJI_GRELEC, 0);
  else
    digitalWrite(ZGORNJI_GRELEC, 1);
  return; 
}

void heat(){
  char i = 0;
  int spodnji[3]={0,0,0};
  int zgornji[3]={0,0,0};
  
  digitalWrite(ZGORNJI_GRELEC, 1);
  digitalWrite(SPODNJI_GRELEC, 1);
  
  do{
    spodnji[i]=(int)spodnji_thermocouple.readCelsius();
    zgornji[i]=(int)zgornji_thermocouple.readCelsius();
    delay(1000);
    i++;
    i%=3;
  }while((zgornji[0]+zgornji[1]+zgornji[2])/3 < TARGET_TEMP - 20 && (spodnji[0]+spodnji[1]+spodnji[2])/3 < TARGET_TEMP - 20 )
  
  digitalWrite(ZGORNJI_GRELEC, 0);
  digitalWrite(SPODNJI_GRELEC, 0);
}

void bake(){
  is_baking = 1;
}


