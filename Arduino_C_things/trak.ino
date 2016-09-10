/**
 * File s funkcijami za nadzor nad premikanjem traka.
 */

static char dir = 1;


void trak_start(void)
{
  digitalWrite(ATTINY_PIN, 0);
}

void trak_stop(void)
{
  digitalWrite(ATTINY_PIN, 1);
}

void trak_init(void)
{
  pinMode(ATTINY_PIN, OUTPUT);
  pinMode(TRAK_ENA_PIN, OUTPUT);
  digitalWrite(ATTINY_PIN, 0);
}

