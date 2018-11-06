#ifndef LED_H
#define LED_H

class Led {
	public:
		static int run(int pin, bool ledOn);
	private:
		Led() = delete;
};

#endif