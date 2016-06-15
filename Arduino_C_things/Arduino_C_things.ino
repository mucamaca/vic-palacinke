/**
 * main file brez main funkcije, ker je arduino DDE (Disintegrated Development Environment) neumen.
 */

#include "constant.h"
//void trak_init();
//void masa_init();
long baking_start;
bool trak_moving = 0;
bool pancake_found = 0;
int lpp_count = 0;

// k33pt4lk1ng4ndn013xpl0d3s

void setup(){
  //while(comm_init())
    delay(400);
  Serial.begin(9600);
  grelci_init();
  write("grelci OK",1,0);
  trak_init();
  write("trak OK", 1, 0);
  masa_init();
  write("masa OK",1, 0);
  heat();
  write("SEGRETO", 1,0);
}

void loop(){
  if(!(lpp_count % 10))
    check_grelci();
  check_infrared();
  digitalWrite(ATTINY_PIN, trak_moving);
  
  /*
  if(baking_start){
    int c_bake_time = (int)(millis() - baking_start);
    if(c_bake_time > BAKING_TIME - 10000){
      dispense_pancake();
    }else if(c_bake_time > BAKING_TIME){
      trak_moving = 1;
      digitalWrite(ATTINY_PIN, trak_moving);
      baking_start = 0;
    }
  }else{
    check_infrared();
  }
  */
  delay(100);
}

