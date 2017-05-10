/**
 * File s funkcijami za nadzor nad premikanjem traka.
 */

#include <Stepper.h>

static Stepper trak_stepper(800, TRAK_PUL_PIN, TRAK_DIR_PIN);

void trak_test(){trak_stepper.step(-200);}

void trak_move(){
  int i;
  //digitalWrite(TRAK_ENA_PIN,1);
  delay(200);
  for(i=0;i<RAZDALJA_MED_GRELCI/2;i++){
    trak_stepper.step(-2);
    delay(1);
  }  
  
}
