/**
 * funkcije za komunikacijo z RPi-jem in interpretacijo errorjev
 */


void comm_check(uint64_t *error_bit_mask)
{
  Serial.write(42);

  char i;
  for(i = 0; i < 20 && !Serial.available(); i++)
    delay(100);

  if(i == 20)
    *error_bit_mask |= HANDSHAKE_TIMED_OUT;
  else if(Serial.read() != 42)
    *error_bit_mask |= WRONG_HANDSHAKE;
}


void comm_init(uint64_t *error_bit_mask)
{
  Serial.begin(9600);
  comm_check(error_bit_mask);
}

 
void write(const char *message, bool init, bool warning)
{
  if(init)
    Serial.write("[Init]");
  if(warning)
    Serial.write("[Warning]");
  else
    Serial.write("[Info]");
  Serial.write(':');
  Serial.write(message);
  Serial.write('\n');
}

void error_write(uint64_t *error_bit_mask)
{
  Serial.write(0);
  char i, *foo;
  for(foo = (char *) error_bit_mask, i = 0; i < 4; i++)
    write(foo);
}

short read()
{
  if(Serial.available())
    return Serial.read();
  else
    return -1;
}

void make_use_of_errors(uint64_t *error_bit_mask)
{
  //TODO
}

void clear_error_bit_mask(uint64_t *error_bit_mask)
{
  memset(error_bit_mask, 0, 8);
}
