// Timer

#ifndef TIMER_H
#define TIMER_H

#include "Arduino.h"

class Timer
{
	public:
		Timer();
		void tickAt(unsigned long ms);
		void tickIn(unsigned long ms);
		void tickEvery(unsigned long ms);
		void tickNowAndEvery(unsigned long ms);
		void stop();	// stop any active timer
		bool ticked();	// call this at frequent intervals (or as required)
		char *name;		// client can assign name to timer, for logging identification
		
		static const unsigned long OneSecond =    1000UL;	//    1 * 1000 ms
		static const unsigned long OneMinute =   60000UL;	//   60 * 1000 ms
		static const unsigned long OneHour   = 3600000UL;	// 3600 * 1000 ms
		
	private:
		bool _active;					// true whilst waiting for a tick
		unsigned long _repeat_ms;		// 0 if non repeating
		unsigned long _nextTick;
};

#endif
