enum readvalues{
  err,
  voidPancake,
  namaz1,
  namaz2 //itd 14 namazov 
}
void pin_init(){
  char c;
  for(c=22;c<26;c++){
    pinMode(c,OUTPUT);
    digitalWrite(c,0);  
  }
  for(c=26;c<30;c++){
    pinMode(c,INPUT);
  }
}

