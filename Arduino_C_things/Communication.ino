int initComm(){
  Serial.begin(9600);
  Serial.write((byte)42);
  if(Serial.read()!=42)
    return -1;
  else
    return 0;
}

