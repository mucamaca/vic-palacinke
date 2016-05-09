#include <Stepper.h>

Stepper trak_stepper = Stepper(1600, TRAK_PUL_PLUS, TRAK_PUL_MINUS, TRAK_DIR_PLUS, TRAK_DIR_MINUS);

void step_trak(int steps){
  trak_stepper.step(steps);
}

