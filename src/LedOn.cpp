#include <string>
#include <vector>
#include <wiringPi.h>
#include "LedOn.h"

int LedOn::run(std::string led) {
	if (wiringPiSetup() == -1)
		return -1;
	
	pinMode(0, OUTPUT);
	
	if (led.compare("LED 1") == 0)
		digitalWrite(0, 1);
	
	return 0;
}