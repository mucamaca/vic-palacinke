/**
 * File s funkcijami za nadzor nad premikanjem traka.
 */

static char dir = 1;

void trak_init(void)
{
  pinMode(ATTINY_PIN, OUTPUT);
  pinMode(TRAK_ENA_PIN, OUTPUT);
}

void trak_stop(void)
{
  digitalWrite(TRAK_ENA_PIN, 1);
}

void trak_start(void)
{
  digitalWrite(TRAK_ENA_PIN, 0);
}

void trak_invert(void)
{
  digitalWrite(TRAK_ENA_PIN, !digitalRead(TRAK_ENA_PIN));
}

void trak_dir_forward(void)
{
  dir = 1;
  digitalWrite(ATTINY_PIN, 1);
}

void trak_dir_backward(void)
{
  dir = 0;
  digitalWrite(ATTINY_PIN, 0);
}

void trak_dir_invert(void)
{
  dir = !dir;
  digitalWrite(ATTINY_PIN, dir);
}

