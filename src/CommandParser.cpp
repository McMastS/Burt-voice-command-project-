#include <string>
#include "CommandParser.h"
#include "LedOn.cpp"
#include "LedOff.cpp"
#include "Weather.h"

void CommandParser::runCommand(vector<std::string> command) {
	if (command[0].compare("light") == 0 || command[0].compare("lights")) {
		if (command[1].compare("on"))
			LedOn::run();
		else
			LedOff::run();
	}

	if (command[0].compare("weather") == 0) {
		Weather::currentForecast();
	}
}