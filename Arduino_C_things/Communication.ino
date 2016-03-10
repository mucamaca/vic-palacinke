/*
 * funkcije za komunikacijo z RPi-jem
 */

#define handshake 42


char init_comm(){
  Serial.begin(9600);
  return check_comm();
}

char check_comm(){
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
