// Dummy file za compilat

#include "../communication.h"
#ifndef Arduino_h //ce ne laufa na arduinu testira z stdinom pa stdoutom
#include <stdio.h>

void main(){
  printf("It twerks");
}

#else // drgac pa nardi setup in loop pa konca

void setup(){};
void loop(){};

#endif
