union pancake_counter_t{
  char segments[2];
  uint16_t whole;
} num_of_pancakes;

uint16_t read_pancake_number(){
  num_of_pancakes.segments[0] = EEPROM[0];
  num_of_pancakes.segments[1] = EEPROM[1];
  return num_of_pancakes.whole;
}

void add_pancake(){
  num_of_pancakes.whole++;
  EEPROM[0] = num_of_pancakes.segments[0];
  EEPROM[1] = num_of_pancakes.segments[1];  
}


