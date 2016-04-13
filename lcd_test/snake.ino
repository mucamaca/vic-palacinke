#include <Adafruit_ssd1306syp.h>
#define SDA_PIN 3
#define SCL_PIN 2
Adafruit_ssd1306syp display(SDA_PIN,SCL_PIN);
float x=50,y=50;
double smer = 0;
#define hitrost 1.5;
void snakeLoop(){
  //Read input
  update();
  render();
  delay(30);
}

void snakeInit(){
  display.initialize();
}

void update(){
  long raw = analogRead(0) - 512;
  double kot = map(raw,-512,511,14,-15)/(180/3.1415926);
  smer += kot;
  x+=sin(smer)*hitrost;
  y+=cos(smer)*hitrost;
}

void render(){
  display.clear();
  display.drawPixel((int)x, (int)y, WHITE);
  display.update();
}

