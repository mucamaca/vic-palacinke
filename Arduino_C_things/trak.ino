/**
 * File s funkcijami za nadzor nad premikanjem traka.
 */

#include <Stepper.h>

static Stepper trak_stepper(800, TRAK_PUL_PIN, TRAK_DIR_PIN);

void trak_move(int steps){
  int i, mili_remainder, integer_part;
  float float_part, steps_per_second = RAZDALJA_MED_GRELCI / BAKE_TIME; 
  integer_part = (int) steps_per_second
  mili_remainder = millis();
  
  
}
