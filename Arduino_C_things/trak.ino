/**
 * File s funkcijami za nadzor na premikanjem traka.
 */

#include <Stepper.h>

static Stepper trak_stepper = Stepper(1600, TRAK_PUL, TRAK_DIR); // mislm da ni 1600

void step_trak(int steps){
  trak_stepper.step(steps);
  all_steps += steps;
  
}
