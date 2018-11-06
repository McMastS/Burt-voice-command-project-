#include <string>
#include <vector>
#include <wiringPi.h>
#include "LedOff.h"

int LedOff::run(std::string led) {
	if (wiringPiSetup() == -1)
		return -1;
	
	pinMode(0, OUTPUT);
	
	if (led.compare("LED 1") == 0)
		digitalWrite(0, 0);
	
	return 0;
}