#ifndef LED_ON_H
#define LED_ON_H

#include <string>

class LedOn {
	public:
		static int run(std::string led);
	private:
		LedOn() = delete;
};

#endif