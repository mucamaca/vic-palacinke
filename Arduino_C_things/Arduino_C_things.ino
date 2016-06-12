/**
 * main file brez main funkcije, ker je arduino DDE (Disintegrated Development Environment) neumen.
 */

#include "constant.h"

// k33pt4lk1ng4ndn013xpl0d3s

void setup(){
  pinMode(4,OUTPUT);
  digitalWrite(4,HIGH);
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(2), lower, FALLING);
  attachInterrupt(digitalPinToInterrupt(3), lift, RISING);
  //while(comm_init())
    delay(400);
  Serial.begin(9600);
  grelci_init();
  write("grelci OK",1,0);
  // trak_init();
  write("trak OK", 1, 0);
  masa_init();
  write("masa OK",1, 0);
  heat();
  write("SEGRETO", 1,0);
}

void loop(){
  check_grelci();
  delay(2000);
}

