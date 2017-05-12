/**
 * main file brez main funkcije, ker je arduino DDE (Disintegrated Development Environment) neumen.
 */
 
#include "constant.h"
#define DBG

char trak_moving = 0;

void setup()
{
  pinMode(DOSING_ENA_PIN, OUTPUT);
  pinMode(TRAK_ENA_PIN,OUTPUT);
  Serial.begin(9600);
  pinMode(STEPPER_5V_PIN, OUTPUT);
Serial.println("MJau");  
  digitalWrite(STEPPER_5V_PIN, HIGH);
  
  
}

int co=1;
void loop()
{
  
  digitalWrite(DOSING_ENA_PIN, 0);
  static int i=0;
  Serial.print(co++);
  Serial.println("     Nalij!");
  //Serial.println(nalij(DOZIRANJE_STEP));
  for (i=0;i<10;i++)
    delay(100*BAKE_TIME);
  trak_move();
}

