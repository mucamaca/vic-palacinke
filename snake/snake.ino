#include <Adafruit_ssd1306syp.h>
#define SDA_PIN 13
#define SCL_PIN 12
Adafruit_ssd1306syp display(SDA_PIN, SCL_PIN);

struct piece{
  char x;
  char y;
};

struct snake_t{
  char x;
  char y;
  char ldx;
  char ldy;
  char index;
  char len;
  struct piece *arr;
};

long ranx = 120, rany = 43;
struct snake_t *snake;
char obstacle_len = 0;
struct piece *obst;


void update_snake(){
  snake->arr[snake->index].x = snake->x;
  snake->arr[snake->index].y = snake->y;
  snake->index = (snake->index + 1) % snake->len;
}
  

void move(){
  char dx = 0,dy = 0;
  if(analogRead(5) - 512 < -100){
    dx = -1;
  }
  else if(analogRead(5) - 512 > 100){
    dx = 1;
  }
  if(analogRead(4) - 512 < -100){
    dy = 1;
  }
  else if(analogRead(4) - 512 > 100){
    dy = -1;
  }
  bool mov = 1;
  if(dx && !dy)
    snake->x += 4 * dx;
  else if(dy && !dx)
    snake->y += 4 * dy;
  else if(dy && dx){
    snake->y += 2 * dy;
    snake->x += 2 * dx;
  }else{
    snake->x += 2 * snake->ldx;
    snake->y += 2 * snake->ldy;
    mov = 0;
  }
  if(mov){
    snake->ldx = dx;
    snake->ldy = dy;
  }
  
  //popravi tole, da se ne bo dalo ful ostro zavijat
}

void collision(){};
void eat(){};

void update(){
  move();
  collision();
  eat();
  update_snake();
}

void draw_snake(){
  char i = 0;
  while(i++ < snake->len){
    if((i + 1) % snake->len != snake->index)
      display.drawLine(snake->arr[i % snake->len].x, snake->arr[i % snake->len].y, 
          snake->arr[(i + 1) % snake->len].x, snake->arr[(i + 1) % snake->len].y, WHITE);
  }
}

void end_game(){
  char i;
  delay(200);
  for(i = 0; i < 5; i++){
    render();
    delay(100);
  }
  free(snake);
  free(obst);
  //goto menu;
}

void render(){
  display.clear();
  draw_snake();
  display.drawPixel(snake->x, snake->y, WHITE);
  display.update();
}

void setup(){
  display.initialize();
  snake=(struct snake_t *)malloc(sizeof(struct snake_t));
  //snake_init(snake);
  char i;
  for(i = 1; i < snake->len * 4; i += 4){
    display.drawPixel(snake->x, snake->y + i, WHITE);
  }
}

void loop(){
  
  update();
  render();
}

