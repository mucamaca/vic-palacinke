/*
 * main file brez main funkcije, ker je arduino IDE/language retardiran
 */
long all_steps = 0;
//char pancake[STEVILO_PALACINK];
//bool should_dispense = true;

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
  delay(900);
  grelci();
  //steper.obrni(3);
}

