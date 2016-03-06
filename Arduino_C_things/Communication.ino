#include <arduino.h>

int initComm(){
  Serial.begin(9600);
  return check_comm();
}

int check_comm(){
  Serial.write((byte)42);
  if(Serial.read()!=42)
    return -1;
  else
    return 0;
}
