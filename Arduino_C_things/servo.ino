/*
 * File z vsemi inicializacijami servomotorjev in 
 * vsemi funkcijami na servomotorjih, ki jih rabmo.
 */
 
 Servo dosing_servo;
 
char init_servos(){
  if (NUMBER_OF_SERVOS == 0) {
    write("No servos initialized, because of NUMBER_OF_SERVOS set to 0 in constant.ino", 1, 1);
    return 0;
  }
    
  write("__init__ servo za doziranje", 1, 0);
  dosing_servo.attach(DOSING_SERVO_PIN);
  if(!dosing_servo.attached()){
    return 42; //some to-be-defined nonzero code
  }
  write("OK", 1, 0);
  
  
  // other servos.
}

void 
 
