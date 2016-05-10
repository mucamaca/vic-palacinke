/**
 * main file brez main funkcije, ker je arduino DDE (Disintegrated Development Environment) neumen
 */

long all_steps = 0, last_millis = 0;
long pancake[STEVILO_PALACINK];
bool should_dispense = true;
bool is_baking = false;

void setup(){
  //while (init_comm())  // don't proceed if no RPi connected
  //write("Connected", init=1, warning=0);
  Serial.begin(9600);
  grelci_init();
}

void loop(){
  // masa
  check_masa(); 

  // grelci
  grelci();
  
  
  
  // Stvar, ki skrbi, da je med dvema iteracijama loopa vsaj 1000 ms (zaradi termoclenov)
  if (millis() - last_millis < 1000)
    delay(1000 - (millis() - last_millis));
  last_millis = millis();
}

