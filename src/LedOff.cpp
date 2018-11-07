#include <string>
#include <vector>
#include <wiringPi.h>
#include "LedOff.h"

int LedOff::run() {
	if (wiringPiSetup() == -1)
		return -1;
	
	pinMode(0, OUTPUT);
	digitalWrite(0, 0);
	
	return 0;
}