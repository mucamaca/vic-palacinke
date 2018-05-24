/**
 * main file brez main funkcije, ker je arduino DDE (Disintegrated Development Environment) neumen.
 */
 
#include "constant.h"

char trak_moving = 0;

#define DBG

void setup()
{

    
  pinMode(STEPPER_5V_PIN, OUTPUT);
  digitalWrite(STEPPER_5V_PIN, 1);

  Serial.begin(9600);
  Serial.println("Running...");  

    heating_setup();

  trak_setup();
    
  dosing_setup();
  pinMode(12,OUTPUT);
  digitalWrite(12, 1);
}




int co=1;
void loop()
{
  Serial.println("lkhasdf");
 long m=millis();
 //nalij(DOZIRANJE_STEP);
 //nalij(DOZIRANJE_STEP);
  while(millis()-m< BAKE_TIME*1000){
    delay(BAKE_TIME);
  }
  
  trak_move();
    int i=0;
    nalij(DOZIRANJE_STEP);
}

