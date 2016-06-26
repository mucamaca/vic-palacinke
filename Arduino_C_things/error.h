#define ULTRASONIC_ERROR 1<<0 
// 1

#define MASA_ERROR 1<<1 
// 2

#define ZGORNJI_THERMOCOUPLE_ERROR 1<<2
//4

#define SPODNJI_THERMOCOUPLE_ERROR 1<<3
//8

#define HANDSHAKE_TIMED_OUT 1<<4
//16

#define WRONG_HANDSHAKE 1<<5
//32

uint64_t error_bit_mask = 0;
