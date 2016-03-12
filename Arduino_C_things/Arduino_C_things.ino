/*
 * main file brez main funkcije, ker je arduino IDE retardiran
 */

#define bananas "bananas"

void setup() {
  Serial.begin(9600)
  while (init_comm())  // don't proceed if no RPi connected
    delay(200);
  if (!NUMBER_OF_SERVOS)
    write("NUMBER OF SERVOS is set to zero!!", init = 1, warning = 1);
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
