union pancake_counter_t{
  char segments[2];
  uint16_t whole;
};

uint16_t read_pancake_number(){
  union pancake_counter_t num_of_pancakes;
  num_of_pancakes.segments[0] = EEPROM[0];
  num_of_pancakes.segments[1] = EEPROM[1];
  return num_of_pancakes.whole;
}


