/*
 * Funkcije za branje inputa z infrardečega senzorja in ugotavljanje, a je palačinka, al je ni.
 */
 
void check_infrared(){
  if(!pancake_found && analogRead(0) > 500){
    pancake_found = 1;
  }else if(pancake_found && analogRead(0) < 500){
    pancake_found = 0;
    delay(200);
    trak_moving = 0;
    digitalWrite(ATTINY_PIN, trak_moving);
    baking_start = millis();
  }
}
