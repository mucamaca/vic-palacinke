/**
 * File z logging funkcijami za sporocanje debuging sporocil v log na RPi-ju
 */

 
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
  }else{
    success_write();
  }
  return errno;
}

char success_write(){
  Serial.write(0);
  return 0;
}

