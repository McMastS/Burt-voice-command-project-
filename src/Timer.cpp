#include "Timer.h"

void Timer::runTime(double time){
	
  sleep(time);
  std::cout << "Time up" << std::endl;
}

int main(){
	
	double time = 3;
	
	Timer::runTime(time);

	return 0;
}
