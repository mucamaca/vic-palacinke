/*
 * main file brez main funkcije, ker je arduino IDE/language retardiran
 */
long long steps = 0;
char pancake[STEVILO_PALACINK];
bool should_dispense = true;

void setup(){
  //while (init_comm())  // don't proceed if no RPi connected
  delay(200);
  Serial.begin(9600);
  Serial.println(grelci_init());
  //write("Connected", init=1, warning=0);
}

void loop(){
  if (should_dispense && check_masa() >= 3){
    should_dispense = false;
    dispense_pancake();
    
  }
  delay(900);
  grelci();
  //Move stepper
  steper.obrni(3);
}

