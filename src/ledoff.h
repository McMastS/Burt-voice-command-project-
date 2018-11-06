#include "icommand.h"

class Ledff: public ICommand {
	public:
		LedOff(int pin);
		int run() override;
	private:
		int pin = 0;
};