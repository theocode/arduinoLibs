// TestTimer

#include "Arduino.h"
#include "Timer.h"

Timer timer;
void setup()
{
  Serial.begin(9600);
  while (!Serial);
  
  Serial.print("Ticking every 2 secs, millis() = "); Serial.println(millis());  
  timer.tickEvery(2000);  
}

void loop()
{
  if (timer.ticked())
  {
    Serial.println("Timer Ticked, millis() = "); Serial.println(millis());
  }
}

