#include "icommand.h"

class LedOn: public ICommand {
	public:
		LedOn(int pin);
		int run() override;
	private:
		int pin = 0;
};