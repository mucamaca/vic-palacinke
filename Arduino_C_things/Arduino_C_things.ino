/**
 * main file brez main funkcije, ker je arduino DDE (Disintegrated Development Environment) neumen.
 */

#include "constant.h"

long all_steps = 0;
long pancake[2];
bool should_dispense = true;
bool is_baking = false; 

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
  //heat();
  write("SEGRETO", 1,0);
}

void loop(){
  step_trak(&all_steps);
  int i;
  for(i = 0; i < 2; i++){
    /*switch(all_steps - pancake[i]){
      case RAZDALJA_DO_GRELCEV:
        write("going to bake...", 0,0);
        bake();
        break;
      case RAZDALJA_DO_ZVIJANJA:
        write("going to roll", 0,0);
        zvij();
        break;
      case END_OF_TRAK:
        write("going to dispense",0,0);
        dispense_pancake();
        break;
    }*/
  }
  check_grelci();
  //write("cycle_completed",0,0);
  
}

