#include "Timer.h"

void Timer::runTime(double time){
	
  sleep(time);
  std::cout << "Time up" << std::endl;
}
