/**
 * File s funkcijami za nadzor na premikanjem traka.
 */

#include <Timer.h>

Timer t;


char trak_init(){
  pinMode(TRAK_PUL_PIN, OUTPUT);
  t.oscillate(TRAK_PUL_PIN, 1, 1); // podpicje, ostani tukaj z mano

  pinMode(TRAK_DIR_PIN, OUTPUT);
  digitalWrite(TRAK_PUL_PIN, 1); // ce se vrti v napacno smer nastav to na 0
}

void step_trak(int * steps){
  if(is_baking)
    return;
  t.update;
  (*steps)++; 
  int i;
  for(i = 0; i < 2; i++){
    if(*steps - pancake[i] == RAZDALJA_DO_GRELCEV)
      bake();
    else if(*steps - pancake[i] == RAZDALJA_DO_ZVIJANJA)
      zvij();
  }
}
