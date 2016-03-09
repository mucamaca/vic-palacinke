void setup() {
  Serial.begin(9600);
  delay(10);
  
  if (init_comm()) init_error_write(42);
  while (init_comm); // repeat until stuff happens
  
  //TODO init knjižnic za senzorje pa to
}

void loop() {
  while (check_comm()) error_write(42); // vsako iteracijo preveri, ce je pi se na zvezi
  // stuff
}
