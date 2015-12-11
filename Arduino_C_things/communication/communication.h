#ifndef communication_h //preprocessor komande da se izognemu veckratnemu importanju in vsemu sranju
#define communication_h

typedef char read_t;
typedef char write_t;

const read_t idle,
	     void_pancake, 
	     // tuki pridejo ostali okusi (ko si jih bomo zmislili)
	     err;

const write_t ok,
	      err_no_mass,
	      err_stuffing_not_available;

void comm_init();

void comm_write(write_t value);

read_t comm_read();

void cat();

#endif
