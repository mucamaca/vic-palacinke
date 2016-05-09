/**
 * main file brez main funkcije, ker je arduino DDE (Disintegrated Development Environment) neumen
 */

long all_steps = 0, last_millis = 0;
long pancake[STEVILO_PALACINK];
bool should_dispense = true;

void setup(){
  //while (init_comm())  // don't proceed if no RPi connected
  //write("Connected", init=1, warning=0);
  Serial.begin(9600);
  grelci_init();
}

void loop(){
  //if (should_dispense && check_masa() >= 3){
    //should_dispense = false;
    //dispense_pancake();
  // }
  
  grelci();
  //steper.obrni(3);
  if (millis() - last_millis < 1000){
    delay(1000 - (millis() - last_millis));
  last_millis = millis();
}

