/**
 * File s funkcijami za upravljanje grelcev in pecenje. 
 */


#include <max6675.h>


static MAX6675 spodnji_thermocouple(SPODNJI_THERMO_CLK, SPODNJI_THERMO_CS, SPODNJI_THERMO_DO);
static MAX6675 zgornji_thermocouple(ZGORNJI_THERMO_CLK, ZGORNJI_THERMO_CS, ZGORNJI_THERMO_DO);


struct mow{
  long time;
  float spodnji;
  float zgornji;
};

static struct mow mes;


static void update(void)
{
  if(millis() - mes.time > 1000){
    mes.zgornji = zgornji_thermocouple.readCelsius();
    mes.spodnji = spodnji_thermocouple.readCelsius();
    mes.time = millis();
  }
}


static void check_for_error(uint64_t *error_bit_mask)
{
  if( (int) mes.zgornji == 0 || mes.zgornji == NAN)
    *error_bit_mask |= ZGORNJI_THERMOCOUPLE_ERROR;
  if( (int) mes.spodnji == 0 || mes.spodnji == NAN)
    *error_bit_mask |= SPODNJI_THERMOCOUPLE_ERROR;
}


void grelci_init(uint64_t *error_bit_mask)
{
  mes.spodnji = -1;
  mes.zgornji = -1;

  update();
  check_for_error(error_bit_mask);
  
  pinMode(SPODNJI_GRELEC, OUTPUT);
  pinMode(ZGORNJI_GRELEC, OUTPUT);

  digitalWrite(ZGORNJI_GRELEC, 1);
  digitalWrite(SPODNJI_GRELEC, 1);
}


void check_grelci(uint64_t *error_bit_mask)
{
  update();
  check_for_error(error_bit_mask);  

  if( (int) zgornji_thermocouple.readCelsius() < ZGORNJI_TARGET_TEMP)
    digitalWrite(ZGORNJI_GRELEC, 1);
  else
    digitalWrite(ZGORNJI_GRELEC, 0);

  if( (int) spodnji_thermocouple.readCelsius() < SPODNJI_TARGET_TEMP)
    digitalWrite(SPODNJI_GRELEC, 1);
  else
    digitalWrite(SPODNJI_GRELEC, 0);
  return;
}


int read_temperature_zgornji(void)
{
  update();
  return (int) mes.spodnji;
}


int read_temperature_spodnji(void)
{
  update();
  return (int) mes.spodnji;
}


void heat(void)
{
  digitalWrite(ZGORNJI_GRELEC, 1);
  digitalWrite(SPODNJI_GRELEC, 1);
  
  do{
    mes.spodnji = spodnji_thermocouple.readCelsius();  
    delay(1000);
    
    Serial.print(mes.spodnji);
    //Serial.println(" %"); // izpise procentualno kolksen delez temperature je dosezen
    //TODO - naredi da bo izpisalo tudi izracun casa, ki ga bo rabil, da pride do ta prave temperature
  
  }while(mes.spodnji < SPODNJI_TARGET_TEMP);
  
  digitalWrite(ZGORNJI_GRELEC, 0);
  digitalWrite(SPODNJI_GRELEC, 0);
}


