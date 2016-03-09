void write(char *message){
  Serial.write("Info: ");
  Serial.write(*message); // nism preprican, a je tle message al *message, mislm da ta drugo.
  Serial.write('\n');
}

void init_write(char *message){
  Serial.write("Init: ");
  write(*message);
}

void error_write(int errno){
  Serial.write("Error ")
  Serial.write(errno/100+'0');
  Serial.write((errno%100)/10+'0');
  Serial.write(errno(%10)+'0');
  Serial.write(':');
}

void init_error_write(int errno){
  Serial.write("Init: ");
  error_write(errno);
}
