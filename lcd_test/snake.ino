#include <Adafruit_ssd1306syp.h>
#define SDA_PIN 3
#define SCL_PIN 2
Adafruit_ssd1306syp display(SDA_PIN,SCL_PIN);

struct piece_of_snake{
  char x;
  char y;
};

char x=50,y=50;
char ldx=0;
char ldy=1;
char snake_index=0;
char snake_len=10;
struct piece_of_snake *obst=(struct piece_of_snake *)malloc(sizeof(struct_piece_of_snake)*0);
struct piece_of_snake snake_arr[10];
#define hitrost 1.5

void snakeInit(){
  display.initialize();
  char i;
  for(i=0;i<snake_len*2;i+=2){
    display.drawPixel((char)x,(char)y+i,WHITE);
  }
}


void update_snake(struct piece_of_snake *snake, char x, char y){
  snake[snake_index].x=x;
  snake[snake_index].y=y;
  snake_index=(snake_index+1)%snake_len;
}
  
void draw_snake(struct piece_of_snake *snake, char len){
  char i=0,n=0;
  while(n++<len){
    if((i+1)%len!=snake_index)
      display.drawLine(snake[i%len].x, snake[i%len].y, snake[(i+1)%len].x, snake[(i+1)%len].y, WHITE);
    i++;
  }
}

void move(){
  char dx=0,dy=0;
  if(analogRead(5) - 512<-100){
    dx=-1;
    Serial.println("x < 0");
  }
  else if(analogRead(5) - 512>100){
    dx=1;
    Serial.println("x > 0");
  }
  if(analogRead(4) - 512<-100){
    dy=1;
    Serial.println("y < 0");
  }
  else if(analogRead(4) - 512>100){
    dy=-1;
    Serial.println("y > 0");
  }
  if(dx&&!dy)
    x+=4*dx;
  else if(dy&&!dx)
    y+=4*dy;
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

void collision(struct piece_of_snake *obstacles, struct piece_of_snake *snake, char len){
  return;
}

void update(){
  move();
  collision(obst, snake_arr, snake_len);
  update_snake(snake_arr, (char)x,(char)y);
}

void render(){
  display.clear();
  draw_snake(snake_arr,snake_len);
  display.drawPixel((char)x,(char)y,WHITE);
  display.update();
}


void snakeLoop(){
  //Read input
  update();
  render();
}

