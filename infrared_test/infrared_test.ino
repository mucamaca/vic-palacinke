void setup(){
  Serial.begin(9600);
}
void loop(){
  Serial.println(analogWrite(0));
  delay(500);
}
