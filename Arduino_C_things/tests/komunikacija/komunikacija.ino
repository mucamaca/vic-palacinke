void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int i = Serial.read();
  if (i != -1){
    Serial.println("Got a byte: " + String(i));
  }
}
