/**
 * main file brez main funkcije, ker je arduino DDE (Disintegrated Development Environment) neumen.
 */
 
#include "constant.h"
#define DBG

char trak_moving = 0;

void setup()
{
  Serial.begin(9600);
  pinMode(STEPPER_5V_PIN, OUTPUT);
  digitalWrite(STEPPER_5V_PIN, HIGH);
}

void loop()
{
  trak_move;
  Serial.println("Nalij!");
  Serial.println(nalij(DOZIRANJE_STEP)); 
}

