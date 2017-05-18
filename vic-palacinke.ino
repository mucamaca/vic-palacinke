/**
 * main file brez main funkcije, ker je arduino DDE (Disintegrated Development Environment) neumen.
 */
 
#include "constant.h"
//#define DBG

char trak_moving = 0;

#define DBG

void setup()
{
  pinMode(HEATING_PIN_0, OUTPUT);
  pinMode(HEATING_PIN_1, OUTPUT);
  pinMode(THERMO_INPUT_0, INPUT);
  pinMode(THERMO_INPUT_1, OUTPUT);
  pinMode(DOSING_ENA_PIN, OUTPUT);
  pinMode(TRAK_ENA_PIN,OUTPUT);
  Serial.begin(9600);
  pinMode(STEPPER_5V_PIN, OUTPUT);
Serial.println("MJau");  
  digitalWrite(STEPPER_5V_PIN, HIGH);
   
  digitalWrite(DOSING_ENA_PIN, 1);
  while(1){
    digitalWrite(HEATING_PIN_0, 1);
    digitalWrite(HEATING_PIN_1, 0);
    Serial.println("rebeka dremel ");
    Serial.println("bratje in mama in fotr in stric in teta in soseda in zlata ribica in nutela in pes in die katze in sestre od rebeke dremel");
    Serial.println(digitalRead(THERMO_INPUT_0));
    delay(100);
  }
  
}


int co=1;
void loop()
{
 
  int i=0;
  Serial.print(co++);
  Serial.println("     Nalij!");
  Serial.println(nalij(DOZIRANJE_STEP));
  long m=millis();
  while(millis()-m< BAKE_TIME*1000){
    delay(BAKE_TIME);
    heat();
  }
  
  trak_move();
}

