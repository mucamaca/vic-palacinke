/*
 * Funkcije za branje inputa z infrardečega senzorja in ugotavljanje, a je palačinka, al je ni.
 */

bool find_pancake(){
  static int lx = 0, x = 0;
  if(lx - x < -15 && lx - x > -40){
    lx = x;
    x = analogRead(0);
    return 1;
  }
  lx = x;
  x = analogRead(0);
  return 0;  
}

void check_infrared(){
  if(find_pancake()){
    delay(200);
    trak_moving = 0;
    baking_start = millis();
  }
}
