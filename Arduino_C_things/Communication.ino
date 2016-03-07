#define handshake 42

int initComm(){
  Serial.begin(9600);
  delay(10);
  return check_comm();
}

byte check_comm(){
  Serial.write((byte)handshake);
  //Počaka da je kaj za brat
  while(!Serial.available()){
    delay(10);
  }
  if(Serial.read()!=handshake)
    return 0;
  else
    return 1;
}
