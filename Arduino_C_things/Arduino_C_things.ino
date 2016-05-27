/**
 * main file brez main funkcije, ker je arduino DDE (Disintegrated Development Environment) neumen.
 * bee.
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
  
  grelci_init();

  trak_init();
}

void loop(){
  step_trak(&all_steps);
}

