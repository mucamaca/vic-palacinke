/* Glavne funkcije Arduino side Arduino-Pi komunikacije*/
#include "communication.h"

#ifndef Arduino_h
#include "../tests/comm_test.h"
#endif

/* commenti, k se koncajo z podpicjem so v resnici del kode, sam so commentani zato, 
da mi gcc ne panicari ker niso tiste funkcije definirane
*/

typedef char read_t; // tip, v katerega se shranijo z maline prebrani podatki
typedef char write_t; // tip, ki ga prek pinov posiljamo malini

// konstante, ki definirajo kaj pomeni prejeto sporocilo
// zraven v commentu binarna vrednost
// keep it sorted
// 0-15
const read_t idle = 0, //0000
	     void_pancake = 1, // 0001 
	     // tuki pridejo ostali okusi (ko si jih bomo zmislili)
	     err = 15; //1111

const write_t ok = 0, //0000
	      err_no_masa = 1, //0001
	      err_namaz_not_available = 2;//0010
	      // itd do 15

void pin_init(){
  char c;
  for(c=22;c<26;c++){
    //pinMode(c,OUTPUT);
    //digitalWrite(c,0);  
  }
  for(c=26;c<30;c++){
    //pinMode(c,INPUT);
  }
}

int main(){}; //sam zato, da mi obicni gcc dela, ker je arduino IDE tok zabugan, da nc ne dela in pol pisem kodo v gedit in compilam iz terminala

void comm_write(const write_t value){
  char offset = 0,
	val = value;
  for(;offset < 4;offset++){
    //digitalWrite(25 - offset, val % 2);
    val >> 1;
  }
}

read_t comm_read(){
  read_t value = 0;
  char offset = 0;
  for(;offset < 4;offset++){
      //value += digitalRead(29 - offset) * 2 ^ offset;
  }
  return value;
}

void cat(){ // cat program, for testing purposes // bo odstranjen, pol ko bo vse stestiran
  comm_write(comm_read());
}

