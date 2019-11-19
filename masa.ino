/*
 * File s funkcijami za doziranje, merjenje in mesanje mase.
 */


#include <Stepper.h>


Stepper dosing_stepper(80000, DOSING_PUL_PIN, DOSING_DIR_PIN);

void dosing_enable() {
	digitalWrite(DOSING_ENA_PIN, 1);
}

void dosing_disable() {
	digitalWrite(DOSING_ENA_PIN, 0);
}

void dosing_setup() {
	pinMode(DOSING_ENA_PIN, OUTPUT);
	delay(200);

	dosing_disable();
}

int nalij(int steps)
{
	dosing_enable();
	int i, mil;
	delay(100);
	for (i = 0; i < steps / 2; i++) {  //  spusti palco
		dosing_stepper.step(1);
		delay(DOZIRANJE_DELAY);
	}
	delay(6000);  //  kokcajta se masa naliva na trak
	for (i = 0; i < steps / 2; i++) {  // dvigne palco
		dosing_stepper.step(-1);
		delay(2);
	}
	delay(50);
	dosing_disable();
	return mil;
}
