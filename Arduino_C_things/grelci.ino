/**
 * File s funkcijami za upravljanje grelcev in pecenje. 
 */


#include <max6675.h>


static MAX6675 spodnji_thermocouple(SPODNJI_THERMO_CLK, SPODNJI_THERMO_CS, SPODNJI_THERMO_DO);
static MAX6675 zgornji_thermocouple(ZGORNJI_THERMO_CLK, ZGORNJI_THERMO_CS, ZGORNJI_THERMO_DO);

static struct temperature_measurement{
  long time;
  float spodnji;
  float zgornji;
};

static struct temperature_measurement *mes = {
  .time = 0;
  .spodnji = -1;
  .zgornji = -1;
}

static void update(struct temperature_measuremet *mes)
{
  if(millis() - mes->time > 1000){
    mes->zgornji = zgornji_thermocouple.readCelsius();
    mes->spodnji = spodnji_thermocouple.readCelsius();
    mes->time = millis();
  }
}


static void check_for_error(uint64_t *error_bit_mask)
{
  update(mes);
  if( (int) mes->zgornji == 0 || mes->zgornji == NAN)
    *error_bit_mask |= ZGORNJI_THERMOCOUPLE_ERROR;
  if( (int) mes->spodnji == 0 || mes->spodnji == NAN)
    *error_bit_mask |= SPODNJI_THERMOCOUPLE_ERROR;
}


void grelci_init(uint64_t *error_bit_mask)
{
  check_for_error(&error_bit_mask);
  
  pinMode(SPODNJI_GRELEC, OUTPUT);
  pinMode(ZGORNJI_GRELEC, OUTPUT);

  digitalWrite(ZGORNJI_GRELEC, 1);
  digitalWrite(SPODNJI_GRELEC, 1);
}


void check_grelci(uint64_t *error_bit_mask)
{
  check_for_error(&error_bit_mask);  

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


int read_temperature_zgornji()
{
  update(mes);
  return (int) mes->spodnji;
}


int read_temperature_spodnji()
{
  update(mes);
  return (int) mes->spodnji;
}


void heat()
{
  char i = 0;
  short spodnji[] = {0, 0, 0};

  digitalWrite(ZGORNJI_GRELEC, 1);
  digitalWrite(SPODNJI_GRELEC, 1);

  do{
    spodnji[i] = (int) spodnji_thermocouple.readCelsius();

    delay(1000);
    
    Serial.print(map(spodnji[i], 23, SPODNJI_TARGET_TEMP, 1, 100) );
    Serial.println(' %');
    
    ++i %= 3;
  
  }while( (spodnji[0] + spodnji[1] + spodnji[2]) / 3 < SPODNJI_TARGET_TEMP);
  
  digitalWrite(ZGORNJI_GRELEC, 0);
  digitalWrite(SPODNJI_GRELEC, 0);
}


