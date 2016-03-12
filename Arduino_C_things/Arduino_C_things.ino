/*
 * main file brez main funkcije, ker je arduino IDE retardiran
 */

#define bananas "bananas"

void setup() {
  Serial.begin(9600)
  while (init_comm()) delay(200); // don't proceed if no RPi connected
  if ()
}

void loop() {
  Serial.flush();
  while (error_write(check_comm())) delay(400); // vsako iteracijo preveri, ce je pi se na zvezi
  while (error_write(check_masa())) {
    delay(200);
    // stuff todo if there exists not enough masa
  } 
  // stuff
}
