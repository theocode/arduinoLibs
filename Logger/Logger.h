// Log
// Debug logger

#ifndef LOG_H
#define LOG_H

//-------------------
// Use these macros

// row captions at top of log
#define LOGHEADING()	{logger.heading();}

// construct a log line using LOGSTART(); LOG(x); LOG(x); LOG(x); LOGEND();
#define LOGSTART()		{logger.logStart();}
#define LOG(x)			{if (logger.enabled) Serial.print(x);}
#define LOGEND()		{logger.logEnd();}

// log(x): same as LOGSTART(); LOG(x); LOGEND();
#define LOGLN(x)		{if (logger.enabled) {logger.logStart(); Serial.println(x);}}
//---------------------

class Logger
{
	public:
		Logger();
		void heading();
		void logStart();	// prints log index and timestamp
		void logEnd();		// prints newline
		bool enabled;
	private:
		int ix;
}; // Logger

extern Logger logger;	// ref to global instance

#endif