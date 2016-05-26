/**
 * funkcije za komunikacijo z RPi-jem
 */


#define HANDSHAKE 42

char comm_init(){
  Serial.begin(9600);
  return check_comm();
}

char comm_check(){
  Serial.write(HANDSHAKE);
  //Počaka da je kaj za brat
  while(!Serial.available()){
    delay(10);
  }
  if(Serial.read() != HANDSHAKE)
    return 42;
  else
    return 0;
}

#undef HANDSHAKE 
