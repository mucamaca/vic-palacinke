/*
 * File z vsemi inicializacijami servomotorjev in 
 * vsemi funkcijami na servomotorjih, ki jih rabmo.
 */
 
 Servo dosing_servo;
 
char init_servo(){
  if (NUMBER_OF_SERVOS == 0) {
    write("No servos initialized, because of NUMBER_OF_SERVOS set to 0 in constant.ino", 1, 1);
    return 0;
  }
    
  write("__init__ servo za doziranje", 1, 0);
  if (!dosing_servo.attach(DOSING_SERVO_PIN)) {
    return 42; //some to-be-defined nonzero code manjsi ali enak 63 (ustavi program)
  }
  write("OK", 1, 0);
  
  
  // other servos.
}

void make_pancake(){
  char state=(char)servo.read();
  dosing_servo.write(state+0/*required value*/);
  delay(0/*required value*/); // some computation will come here
  dosing_servo.write(state);
}
 
