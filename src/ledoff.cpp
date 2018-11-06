#include <wiringPi.h>
#include "ledoff.h"

LedOff::LedOff(int pin) {
	this->pin = pin;
}

int LedOff::run() override {
	if (wiringPiSetup() == -1)
		return -1;
	
	pinMode(pin, OUTPUT);
	digitalWrite(pin, 0); 
	return 0;
}