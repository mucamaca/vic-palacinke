/**
 * main file brez main funkcije, ker je arduino DDE (Disintegrated Development Environment) neumen.
 */
 
#include "constant.h"

char trak_moving = 0;

#define DBG

void setup()
{
  heating_setup();

  trak_setup();
    
  dosing_setup();
    
  pinMode(STEPPER_5V_PIN, OUTPUT);
  digitalWrite(STEPPER_5V_PIN, 1);

  Serial.begin(9600);
  Serial.println("Running...");  

  pinMode(12,OUTPUT);
  digitalWrite(12, 1);
}


int co=1;
void loop()
{
 
  int i=0;
  Serial.print(co++);
  Serial.println("     Nalij!");
  Serial.println(nalij(DOZIRANJE_STEP));
  long m=millis();
  while(millis()-m< BAKE_TIME*100){
    delay(BAKE_TIME);
  }
  
  trak_move();
}

