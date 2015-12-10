// Dummy file za compilat

#ifndef Arduino_h //ce ne laufa na arduinu nardi prazen main in konca
#include <stdio.h>

void main(){printf("It twerks")};

#else // drgac pa nardi prazen setup in loop pa konca
#include "../communication.h"

void setup(){};
void loop(){};

#endif
