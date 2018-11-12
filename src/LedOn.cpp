#include <string>
#include <vector>
#include <wiringPi.h>
#include "LedOn.h"

int LedOn::run() {
	if (wiringPiSetup() == -1)
		return -1;
	
	pinMode(0, OUTPUT);
	digitalWrite(0, 1);
	
	return 0;
}