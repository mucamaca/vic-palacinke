/**
 * funkcije za komunikacijo z RPi-jem
 */


char comm_init(){
  Serial.begin(9600);
  return comm_check();
}

#define HANDSHAKE 42

char comm_check(){
  Serial.write(HANDSHAKE);
  //Počaka da je kaj za brat
  while(!Serial.available()){
    delay(100);
  }
  if(Serial.read() != HANDSHAKE)
    return 42;
  else
    return 0;
}

#undef HANDSHAKE 

 
void write(const char message[127], bool init, bool warning){
  Serial.write(127);
  if(init)
    Serial.write("[Init]");
  if(warning)
    Serial.write("[Warning]:");
  else
    Serial.write("[Info]:");
  int i;
  for(i = 0; i < strlen(message); i++){
    Serial.write(message[i]);
  }
  Serial.write('\n');
}
 
char error_write(char errno){
  if(errno){
    Serial.write(errno / 100 + '0');
    Serial.write(errno % 10 + '0');
  }else
    Serial.write(0);
  return errno;
}

char read(){
  if(Serial.available())
    return Serial.read();
  else
    return 0;
}

