/**
 * File s funkcijami za nadzor nad premikanjem traka.
 */

#include <Stepper.h>

static Stepper trak_stepper(800, TRAK_PUL_PIN, TRAK_DIR_PIN);

void trak_init()
{
  //trak_stepper.setSpeed(2);
}

void trak_move(int meow)
{
  int i;
  for(i=0;i<meow;i++){
    trak_stepper.step(-1);
    delay(1);
  }
}
