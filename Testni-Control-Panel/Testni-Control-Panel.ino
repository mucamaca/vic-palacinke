int beltSpeed, heat;
const byte debug = 1;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(1, OUTPUT); //Display
  pinMode(2, OUTPUT); //Še zmeri display
  initGrelci();
}

void loop() {
  // put your main code here, to run repeatedly:
  beltSpeed = analogRead(0);
  heat = map(analogRead(1), 0, 1023, 50, 120);
  grelci(heat);

  if (debug){
    Serial.print("Belt speed: ");
    Serial.println(beltSpeed);
    Serial.print("Heat: ");
    Serial.println(heat);
  }

  delay(200);
}
