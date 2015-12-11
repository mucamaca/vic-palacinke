/* 
Header od testnega fila, za testiranje
Arduino side komunikacije direktno na racunalniku
*/

#ifdef Arduino_h
# error to ne dela na arduinu!
#endif


const char OUTPUT = 0;
const char INPUT = 1;


void pinMode(char pin, char mode);

void digitalWrite(char pin, char value);

int digitalRead(char pin);
