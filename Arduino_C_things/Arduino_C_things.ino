/**
 * main file brez main funkcije, ker je arduino DDE (Disintegrated Development Environment) neumen.
 */

#include "constant.h"

int lpp_count = 0;

void setup(){
  //while(comm_init())
    delay(400);
  Serial.begin(9600);
  grelci_init();
  write("grelci init",1,0);
  trak_init();
  write("trak init", 1, 0);
  masa_init();
  write("masa init",1, 0);
  heat();
  write("SEGRETO", 1,0);
}

void loop()
{
  ++lpp_count;
  check_grelci();
  digitalWrite(ATTINY_PIN, trak_moving);
}

