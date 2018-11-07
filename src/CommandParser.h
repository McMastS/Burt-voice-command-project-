#ifndef CMD_PSR_H
#define CMD_PSR_H

#include <string>

class CommandParser {
	public:
		static void runCommand(vector<std::string> command);
};

#endif