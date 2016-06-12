/*
 * Funkcije za branje inputa z infrardečega senzorja in ugotavljanje, a je palačinka, al je ni.
 */
 
void read_infrared(){
  if(!pancake_found && analogRead(0) > 500){
    pancake_found = 1;
  }else if(pancake_found && analogRead(0) < 500){
    pancake_found = 0;
    delay(200);
    digitalWrite(ATTINY_PIN, 0);
    baking_start = millis();
  }
}
