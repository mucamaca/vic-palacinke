/*
 * File z logging funkcijami za sporocanje debuging sporocil v logfile na RPi-ju
 */



/*
 * za preprosta sporocila v stilu "Segrevam grelce" ali "Palacinka je nared"
 */
 
void write(char *message){
  Serial.write("Info: ");
  Serial.write(*message); // nism preprican, a je tle message al *message, mislm da ta drugo.
  Serial.write('\n');
}


/*
 * za sporocila, ki se posljejo v init fazi programa
 */
 
void init_write(char *message){
  Serial.write("Init: ");
  write(*message);
}


/*
 * funkcija za opozorila, npr. "Nizko stanje mase" ali "Zmanjkuje ________ namaza"
 */
 
void warning_write(char *message){
  Serial.write("Warning: ");
  Serial.write(*message);
  Serial.write("!\n");
}

/*
 * init-time opozorila
 */

void warning_write(char *message){
  Serial.write("Init: ");
  Serial.write(*message);
}


/*
 * za errorje sporoci samo stevilko, opis pa doda java na RPi-ju
 */
 
int error_write(int errno){
  if (errno) {
    Serial.write("Error ");
    Serial.write(errno/100+'0');
    Serial.write((errno%100)/10+'0');
    Serial.write(errno(%10)+'0');
    Serial.write(':');
  }
  return errno;
}


/*
 * init-time errorji
 */
 
int init_error_write(int errno){
 if (errno) {
    Serial.write("Init: ");
    error_write(errno, *message);
 }
 return errno;
}
