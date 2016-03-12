/*
 * File z logging funkcijami za sporocanje debuging sporocil v logfile na RPi-ju
 */


/*
 * za preprosta sporocila v stilu "Segrevam grelce" ali "Palacinka je nared"
 */
 
void write(const char message[127], bool init, bool warning){
  Serial.write(127);
  if (init)
    Serial.write("[Init]");
  if (warning)
    Serial.write("[Warning]:")
  else
    Serial.write("[Info]:");
  int i;
  for (i = 0; i < strlen(message); i++){
    Serial.write(message[i]);
  }
  Serial.write('\n');
}
 
 
/*
 * za errorje sporoci samo stevilko, opis pa doda java na RPi-ju
 */
 
char error_write(char errno){
  if (errno) {
    digitalWrite(13, 1);
    Serial.write(errno/100+'0');
    Serial.write((errno%100)/10+'0');
    Serial.write(errno%10+'0');
  }
  return errno;
}

