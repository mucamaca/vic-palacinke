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

int co=1;
void loop()
{
  static int i=0;
  Serial.print(co++);
  Serial.println("     Nalij!");
  Serial.println(nalij(DOZIRANJE_STEP));
  for (i=0;i<10;i++)
    delay(100*BAKE_TIME);
  trak_move();
}

