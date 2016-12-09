/**
 * File s funkcijami za nadzor nad premikanjem traka.
 */

#include <Stepper.h>

static Stepper trak_stepper(800, TRAK_PUL_PIN, TRAK_DIR_PIN);

void trak_move(int steps){
  int i;
  for(i = 0; i < steps; i++){
    trak_stepper.step(-1);
    delay(1);
  }
}
