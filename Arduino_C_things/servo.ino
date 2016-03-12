/*
 * File z vsemi funkcijami na servomotorjih, ki jih rabmo.
 */

char make_pancake(){
  Servo servo;
  if (!servo.attach(DOSING_SERVO_PIN))
    return 42; // some not-yet-defined errorcode 1- 63
  char state=(char)servo.read();
  dosing_servo.write(state + 0/*required value*/);
  delay(0/*required value*/); // some computation comes here
  dosing_servo.write(state);
  return 0;
}
 
