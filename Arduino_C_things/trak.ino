/**
 * File s funkcijami za nadzor na premikanjem traka.
 */

#include <Stepper.h>

Stepper trak_stepper(1600, TRAK_PUL_PIN, TRAK_DIR_PIN); // mislm da ni 1600

void step_trak(int steps){
  if(is_baking)
    return;
  trak_stepper.step(steps);
  all_steps += steps;  
  int i;
  for(i = 0; i < STEVILO_PALACINK; i++){
    //if(all_steps - pancake[i] == RAZDALJA_DO_GRELCEV)
      bake();
    
   // else if(all_steps - pancake[i] == RAZDALJA_DO_ZVIJANJA)
      //zvij();
    
  }
}
