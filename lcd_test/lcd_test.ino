#include <Adafruit_ssd1306syp.h>
#define SDA_PIN 8
#define SCL_PIN 9
Adafruit_ssd1306syp display(SDA_PIN,SCL_PIN);
void setup()
{
  delay(1000);
  display.initialize();
}
void loop()
{
  display.drawLine(0, 0, 127, 63,WHITE);
  display.update();
  delay(1000);
  display.clear();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.println("Hello, world!");
  display.setTextColor(BLACK, WHITE); // 'inverted' text
  display.println(3.141592);
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.print("0x"); display.println(0xDEADBEEF, HEX);
  display.update();
  delay(2000);
  display.clear();
}
