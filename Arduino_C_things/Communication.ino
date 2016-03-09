/*
 * funkcije za komunikacijo z RPi-jem
 */

#define 42 handshake
#define handshake 42


int init_comm(){
  return check_comm();
}

int check_comm(){
  Serial.write(42);
  //Počaka da je kaj za brat
  while(!Serial.available()){
    delay(10);
  }
  if(Serial.read()!=42)
    return 42;
  else
    return 0;
}
