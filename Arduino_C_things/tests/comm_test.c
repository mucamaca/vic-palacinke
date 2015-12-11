/*
comm_test.c

naredi dummy Arduino funkcije, ki namesto s pinov 
berejo s stdina in namesto na pine pise na stdout.
*/

#ifdef Arduino_h
# error you cannot run this file on arduino
#endif
#include "comm_test.h"
#include <string.h>
#include <stdio.h>

int c=0;
char t[1024];
bool x = false;

void pinMode(char pin, char mode){
  if(!x){
    x=true;
    do{
      scanf("%c ",t[c]);
      ++c;
    }while(t[c-1]!=42);
  }
}
  
int digitalRead(char pin){
  for(c=0;c<=1024;c++){
    if(t[c]==pin){
      return (int) t[c+1];
    }
  }
}

void digitalWrite(char pin,char value){
  printf("%c %c\n",pin,value);
}
