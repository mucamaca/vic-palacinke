#include <Adafruit_ssd1306syp.h>
#define SDA_PIN 3
#define SCL_PIN 2
//Adafruit_ssd1306syp display(SDA_PIN,SCL_PIN);

//joystick y -> 4
//joystick x -> 5

void setup(){
  delay(1000);
  //display.initialize();
  Serial.begin(9600);
  snakeInit();
}
void loop()
{
  /*display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(0,2);
  display.println("Hello, world!");
  display.update();
  delay(2000);
  display.clear();*/
  snakeLoop();
}
