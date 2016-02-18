#include <DallasTemperature.h>
#include <OneWire.h>

OneWire oneWire(4);

DallasTemperature sensors(&oneWire);

void setup(){
  pinMode(2,OUTPUT);
  Serial.begin(9600);
  sensors.begin();
}

void loop(){
  sensors.requestTemperatures();
  Serial.println(sensors.getTempCByIndex(0));
  digitalWrite(2,1);
}
