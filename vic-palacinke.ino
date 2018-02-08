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
 //while(12)
 //trak_clean();
 //return;
  int i=0;
  Serial.print(co++);
  Serial.println(".     Nalij!");
  if(!nalij(DOZIRANJE_STEP)){
    trak_clean();
    return;
  }
  long m=millis();
  while(millis()-m< BAKE_TIME*1000){
    delay(BAKE_TIME);
  }
  
  trak_move();
}

