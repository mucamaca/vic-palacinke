/*
 * main file brez main funkcije, ker je arduino IDE retardiran
 */

/*#include <logging.h>
#include <ultrasonic.h>
#include <constant.h>
#include <masa.h>*/

void setup() {
  if (init_comm() == 42){
    write("Init uspesen.", true);
  }
}

void loop() {
  Serial.flush();
  //while (error_write(check_comm())) delay(200); // vsako iteracijo preveri, ce je pi se na zvezi
  //while (error_write(check_mass())) delay(100); // preveri, ce ma se dost mase
  // stuff
  write("banananas", false);
  delay(1000);
}
