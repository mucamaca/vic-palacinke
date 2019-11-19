void heating_enable() {
	digitalWrite(HEATING_ZGORNJI, 1);
	digitalWrite(HEATING_SPODNJI, 1);
}

void heating_disable() {
	digitalWrite(HEATING_ZGORNJI, 0);
	digitalWrite(HEATING_SPODNJI, 0);
}


void heating_setup() {
	pinMode(HEATING_SPODNJI, OUTPUT);
	pinMode(HEATING_ZGORNJI, OUTPUT);
	heating_enable();
}
