#ifndef Timer_P_h
#define Timer_P_h
#include <Arduino.h>

/* Timer_P library 
MIT license
written by X-Dron
*/

class Timer_P
{
private:
  long TargetMsec;
  long Remains;  
  boolean Old_Condition;  //Previous value of Condition 
  boolean Old_Reset;      //Previous value of Reset
  boolean Old_TimerOut;	  //Previous value of TimerOut
  boolean TimerOut;		  
  boolean TimerRun;
public:
  Timer_P();
  boolean Timer(boolean Condition, boolean Reset,int Mode, long Duration);
  long GetRemains();
};
#endif