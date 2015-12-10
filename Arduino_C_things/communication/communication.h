#ifndef communication_h //preprocessor komande da se izognemu veckratnemu importanju in vsemu sranju
#define communication_h

typedef char read_t;
typedef char write_t;

const read_t idle = 0, //0000
	     void_pancake = 1, // 0001 
	     // tuki pridejo ostali okusi (ko si jih bomo zmislili)
	     err = 15; //1111

const write_t ok = 0, //0000
	      err_no_masa = 1, //0001
	      err_namaz_not_available = 2;//0010
	      // itd do 15

void comm_write(write_t value);

read_t comm_read();

void cat();

#endif
