#include <Adafruit_ssd1306syp.h>
#define SDA_PIN 3
#define SCL_PIN 2
Adafruit_ssd1306syp display(SDA_PIN,SCL_PIN);
float x=50,y=50;
int pos=0;
char arr[10][2];
double smer = 0;
int snake_index=0;
#define hitrost 1.5

void arr_init(char *snk int x, int y, char len){
  int i;
  for(i=0;i<len;i++){
    snk[i][0]=x++;
    snk[i][1]=y++;
  }
}

void snakeInit(){
  display.initialize();
  arr_init(x,y,10);
}

void snakeLoop(){
  //Read input
  update();
  render();
  delay(30);
}

void update_snake(int * snake, int x, int y){
  snake[snake_index][0]=x;
  snake[snake_index][1]=y;
  snake_index=(snake_index+1)%snake_len;
}
  
void draw_snake(char *snk,int len){
  int i;
  for(i=pos;i%len<pos;i++){
    display.drawPixel(snk[i][0],snk[i][1],WHITE);
  }
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

