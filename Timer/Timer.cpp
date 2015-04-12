#include "Logger.h"
#include "Timer.h"

Timer::Timer()
{
	_active = false;
	name = "anon";
} // Timer()

void Timer::tickAt(unsigned long ms)
{
	_nextTick = ms;
	_repeat_ms = 0UL;		// no repeats
	_active = true;
} // tickAt()

void Timer::tickIn(unsigned long ms)
{
	_nextTick =  millis() + ms;
	_repeat_ms = 0UL;		// no repeats
	_active = true;
} // tickIn()

void Timer::tickEvery(unsigned long ms)
{
	_nextTick = millis() + ms;
	_repeat_ms = ms;		// repeat at ms
	_active = true;
} // tickEvery()

void Timer::tickNowAndEvery(unsigned long ms)
{
	_nextTick = millis();	// first tick can happen immediately
	_repeat_ms = ms;		// repeat at ms
	_active = true;
} // tickEvery()

// stop any active timer
void Timer::stop()
{
	_active = false;
} // stop()

bool Timer::ticked()
{
	if (!_active) return false;
	
	// check for tick, and handle rollover
	unsigned long now = millis();
	if ((now - _nextTick) < 0x7fffffffUL)
	{
		if (_repeat_ms != 0UL)
		{
			LOGSTART(); LOG("Timer "); LOG(name); LOG(": Ticked Repeat"); LOGEND();
			_nextTick += _repeat_ms;
			_active = true;
			return true;	// ticked
		}
		else
		{
			LOGSTART(); LOG("Timer "); LOG(name); LOG(": Ticked SingleShot"); LOGEND();
			_active = false;
			return true;	// ticked
		}
	}
	
	return false;			// not ticked
} // ticked()
