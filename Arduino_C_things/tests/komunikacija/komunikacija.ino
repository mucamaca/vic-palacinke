void setup() {
  Serial.begin(9600);
}

void loop() {
  char i = Serial.read();
  if (i != 255) Serial.println("Got a byte: " + i);
}
