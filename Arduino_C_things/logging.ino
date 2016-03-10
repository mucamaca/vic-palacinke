/*
 * File z logging funkcijami za sporocanje debuging sporocil v logfile na RPi-ju
 */



/*
 * za preprosta sporocila v stilu "Segrevam grelce" ali "Palacinka je nared"
 */
 
void write(String message, bool init){
  Serial.write(127);
  if(init) Serial.write("Init:");
  Serial.write("Info:");
  byte i;
  char chars[256];
  message.toCharArray(chars, message.length());
  for (i = 0; i < message.length() + 1; i++){
    Serial.write(chars[i]);
  }
  Serial.write('\n');
}


/*
 * funkcija za opozorila, npr. "Nizko stanje mase" ali "Zmanjkuje ________ namaza"
 */
 
void warning_write(char *message, bool init){
  Serial.write(127);
  if(init) Serial.write("Init:");
  Serial.write("Warning:");
  Serial.write(*message);
  Serial.write('/n');
}

/*
 * za errorje sporoci samo stevilko, opis pa doda java na RPi-ju
 */
 
int error_write(int errno){
  if (errno) {
    Serial.write(errno/100+'0');
    Serial.write((errno%100)/10+'0');
    //Serial.write(errno(%10)+'0');
  }
  return errno;
}

