#ifndef communication_h //prerprocessor komande da se izognemu veckratnemu importanju in vsemu sranju
#define communication_h

typedef char read_t;
typedef char write_t;

void comm_write(write_t value);

read_t comm_read();

void cat();

#endif
