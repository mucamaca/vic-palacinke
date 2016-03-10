/*
 * main file brez main funkcije, ker je arduino IDE retardiran
 */


void setup() {
  while (init_comm()) delay(200); // 
}

void loop() {
  Serial.flush();
  while (error_write(check_comm())) delay(400); // vsako iteracijo preveri, ce je pi se na zvezi
  while (error_write(check_())) {
    delay(200);
    // stuff todo if there exists not enough 
  } // preveri, ce ma se dost mase
  // stuff
  write("banananas", false);
  delay(1000);
  Serial.write(17);
  Serial.write(103);
}
