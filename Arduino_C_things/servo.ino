/*
 * File z vsemi funkcijami na servomotorjih, ki jih rabmo.
 */
 
 // Servo library is retarded

char make_pancake(){
  Servo servo;
  if (!servo.attach(DOSING_SERVO_PIN))
    return 42; // some not-yet-defined errorcode 1- 63
  dosing_servo.write(0/*required value*/);
  delay(0/*required value*/); // some computation comes here
  dosing_servo.write(0/*zacetno stanje*/);
  return 0;
}
 
