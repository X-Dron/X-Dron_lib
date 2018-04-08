/*
* Project: X-Dron_library/Arduino Library
* Library class: Timer_P
* Author: X-Dron, X-Dron@mail.ru
* Copyright: (C) 2015 by X-Dron
* License: GNU GPL v3 (see License.txt)
* Web: https://github.com/X-Dron/X-Dron_lib
*/
#ifndef Timer_P_h
#define Timer_P_h
#include <Arduino.h>

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
  void TimerV(boolean Condition, boolean Reset,int Mode, long Duration);
  boolean Timer(boolean Condition, boolean Reset,int Mode, long Duration);
  boolean Q0();
  long GetRemains();
};
#endif