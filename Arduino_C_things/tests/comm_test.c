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

const char OUT=0;
const char IN=1;

int c=0;
char t[1024];
bool x = false;

char ip=0,
     op=0;
char ins[4]={0,0,0,0};
char outs[4]={0,0,0,0};


void pinMode(char pin, char mode){
  if(!x){
    x=true;
    do{
      scanf("%c ",t[c]);
      ++c;
    }while(t[c-1]!=42);
  }
  if(mode==OUT) outs[op++]=pin;
  else ins[ip++]=pin;
}
  
int digitalRead(char pin){
  x=false;
  for(c=0;c<ip;c++){
       if(ins[c]==pin){
          x=true;  
       }
  }
  if(!x){
       printf("ERROR!");
       return 42;
  }
  for(c=0;c<=1024;c++){
    if(t[c]==pin){
      return (int) t[c+1];
    }
  }
}

void digitalWrite(char pin,char value){
  x=false;
  for(c=0;c<op;c++){
       if(outs[c]==pin){
          x=true;  
       }
  }
  if(!x){
       printf("ERROR!");
       return 42;
  }     
  printf("%c %c\n",pin,value);
}
