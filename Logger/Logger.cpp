// Log.cpp
// Debug logger

#include "Arduino.h"
#include "Logger.h"

Logger::Logger()
{
	ix = 1;
}

void Logger::heading()
{
	enabled = true;
	
	LOG(F("    Ix    Secs.ms  Message\n"));
	LOG(F("------ -------.--- --------------\n"));
} // heading()

void Logger::logStart()
{
	if (!enabled) return;
	
	unsigned long now = millis();	// message timestamp
	char msg[15];
	
	// message index
	sprintf(msg, "%6i ", ix++);
	Serial.print(msg);
	
	// message timestamp
	int secs = now / 1000;
	int msecs = now % 1000;
	sprintf(msg, "%7i.%03i ", secs, msecs);
	Serial.print(msg);
} // logStart()

void Logger::logEnd()
{
	if (enabled)
		Serial.println();
} // logEnd()

Logger logger;		// global instance
