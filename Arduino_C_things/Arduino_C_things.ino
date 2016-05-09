/*
 * main file brez main funkcije, ker je arduino IDE/language retardiran
 */

void setup(){
  //while (init_comm())  // don't proceed if no RPi connected
    delay(200);
  Serial.begin(9600);
  Serial.println(grelci_init());
  //write("Connected", init=1, warning=0);
}

void loop(){
  //while (error_write(check_comm())) delay(400); // vsako iteracijo preveri, ce je pi se na zvezi
  //while (error_write(check_masa())) {
    delay(900);
  grelci();
    // stuff todo if there exists not enough masa 
  // stuff
}
