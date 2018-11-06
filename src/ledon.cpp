#include <wiringPi.h>
#include "ledon.h"

LedOn::LedOn(int pin) {
	this->pin = pin;
}

int LedOn::run() override {
	if (wiringPiSetup() == -1)
		return -1;
	
	pinMode(pin, OUTPUT);
	digitalWrite(pin, 1) ; 
	return 0;
}