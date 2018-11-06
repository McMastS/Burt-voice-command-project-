#include <wiringPi.h>
#include "LED.h"

int LED::run(int pin, bool ledOn) {
	if (wiringPiSetup() == -1)
		return -1;
	
	pinMode(pin, OUTPUT);
	
	if (ledOn)
		digitalWrite(pin, 1);
	else
		digitalWrite(pin, 0);
	
	return 0;
}