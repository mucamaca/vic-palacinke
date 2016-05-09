/*
 * main file brez main funkcije, ker je arduino IDE/language retardiran
 */
int pancake_steps [3];
bool should_dispense = true;

void setup(){
  //while (init_comm())  // don't proceed if no RPi connected
    delay(200);
  Serial.begin(9600);
  Serial.println(grelci_init());
  //write("Connected", init=1, warning=0);
}

void loop(){
  if (should_dispense && check_masa() >= MASA_PER_PANCAKE){
    should_dispense = false;
  }
  delay(900);
  grelci();
}
