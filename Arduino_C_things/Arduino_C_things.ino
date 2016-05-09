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
  if (should_dispense && check_masa() >= 3){
    should_dispense = false;
    dispense_pancake();
    pancake_steps[2] = 1;
    clean_array();
  }
  delay(900);
  grelci();
  //Move stepper
  steper.obrni(3);
}

void clean_array(){
  char arr_len = sizeof(pancake_steps) / sizeof(int);
  for (char i = arr_len - 1; i >= 1; i --){
    if (pancake_steps[i - 1] == 0){
      pancake_steps[i - 1] = pancake_steps[i];
      pancake_steps[i] = 0;
    }
  }
}
