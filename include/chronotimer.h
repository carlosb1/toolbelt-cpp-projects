#ifndef _TIMER_H
#define _TIMER_H

#include <cstdio>
#include <string>
#include <ctime>
#include <chrono>



namespace cvc {
	//msecs
	namespace utils {
		class Timer
		{
		private:
			std::clock_t startTime;
		public:
			inline void start() {		
				startTime = std::clock();
			}
 
			inline int stop() {
				return (int)((( std::clock() - startTime ) / (double) CLOCKS_PER_SEC)*1000);
			}
		};

	}

}

#endif



