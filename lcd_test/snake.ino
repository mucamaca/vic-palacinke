#include <Adafruit_ssd1306syp.h>
#define SDA_PIN 3
#define SCL_PIN 2
Adafruit_ssd1306syp display(SDA_PIN,SCL_PIN);

struct piece_of_snake{
  char x;
  char y;
};

float x=50,y=50;
int ldx=0;
int ldy=1;
int snake_index=0;
char snake_len=10;
struct piece_of_snake snake_arr[10];
#define hitrost 1.5

void snakeInit(){
  display.initialize();
  int i;
  for(i=0;i<snake_len*2;i+=2){
    display.drawPixel((char)x,(char)y+i,WHITE);
  }
}


void update_snake(struct piece_of_snake *snake, char x, char y){
  snake[snake_index].x=x;
  snake[snake_index].y=y;
  snake_index=(snake_index+1)%snake_len;
}
  
void draw_snake(struct piece_of_snake *snake, int len){
  int i=0,n=0;
  while(n++<len){
    if((i+1)%len!=snake_index)
      display.drawLine(snake[i%len].x, snake[i%len].y, snake[(i+1)%len].x, snake[(i+1)%len].y, WHITE);
    i++;
  }
}

void move(){
  char dx=0,dy=0;
  if(analogRead(5) - 512<100){
    dx=-1;
    Serial.println("x < 0");
  }
  else if(analogRead(5) - 512>100){
    dx=1;
    Serial.println("x > 0");
  }
  if(analogRead(4) - 512<100){
    dy=1;
    Serial.println("y < 0");
  }
  else if(analogRead(4) - 512>100){
    dy=-1;
    Serial.println("y > 0");
  }
  if(dx&&!dy)
    x+=3*dx;
  else if(dy&&!dx)
    y+=3*dy;
  else if(dy&&dx){
    y+=2*dy;
    x+=2*dx;
  }else{
    x+=ldx;
    y+=ldy;
  }
  ldx=dx;
  ldy=dy;
}

void update(){
  move();
  update_snake(snake_arr, (char)x,(char)y);
}

void render(){
  display.clear();
  draw_snake(snake_arr,snake_len);
  display.drawPixel((int)x,(int)y,WHITE);
  display.update();
}


void snakeLoop(){
  //Read input
  update();
  render();
}

