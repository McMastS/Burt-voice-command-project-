#ifndef LED_OFF_H
#define LED_OFF_H

#include <string>

class LedOff {
	public:
		static int run(std::string led);
	private:
		LedOff() = delete;
};

#endif