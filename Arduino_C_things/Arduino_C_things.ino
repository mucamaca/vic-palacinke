/**
 * main file brez main funkcije, ker je arduino DDE (Disintegrated Development Environment) neumen.
 */
 
#include "constant.h"
#include "error.h"
#define DBG

char trak_moving = 0;

void setup()
{
  //while(comm_init())
    delay(400);
  
  Serial.begin(9600);
  //error_bit_mask = (uint64_t *) malloc(sizeof(uint64_t));
  pinMode(STEPPER_5V_PIN, OUTPUT);
  digitalWrite(STEPPER_5V_PIN, HIGH);
  write("trak OK", 1, 0);
  // masa_init();
  write("masa OK",1, 0);
  
}

void loop()
{
  trak_move;
  write("Nalij!", 0, 0);
  //Serial.println(nalij(DOZIRANJE_STEP)); 
}

