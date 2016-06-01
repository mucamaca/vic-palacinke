/*
 * Funkcije za branje inputa z infrardečega senzorja in ugotavljanje, a je palačinka, al je ni.
 */
 
bool read_infrared(){
  if(analogRead(0) > 500)
    return 1;
  else
    return 0;
}
