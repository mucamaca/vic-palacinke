/*
 * main file brez main funkcije, ker je arduino IDE retardiran
 */

#include <logging.h>
#include <ultrasonic.h>
#include <constant.h>
#include <masa.h>

void setup() {
  write("Starting...");
  delay(200);
  write("initializing serial...");
  Serial.begin(9600);
  delay(10);
  
  
  delay(300);
  write("Checking for RPi serial connection...")
  while (init_error_write(init_comm())) delay(200);
  digitalWrite(13, 0);
  
  delay(300);
  write("Checking for ultrasonic sensor...")
  while (init_error_write(init_sonic())) delay(200); //repeat until stuff happens
  digitalWrite(13,0);
  //TODO init knjižnic za senzorje pa to
  write("Done initializing.");
  write("Cakam na narocilo") ;
}

void loop() {
  Serial.flush();
  while (error_write(check_comm())) delay(200); // vsako iteracijo preveri, ce je pi se na zvezi
  while (error_write(check_mass())) delay(100); // preveri, ce ma se dost mase
  // stuff
}
