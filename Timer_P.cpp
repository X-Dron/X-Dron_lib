/*
* Project: X-Dron_library/Arduino Library
* Library class: Timer_P
* Author: X-Dron, X-Dron@mail.ru
* Copyright: (C) 2015 by X-Dron
* License: GNU GPL v3 (see License.txt)
* Web: https://github.com/X-Dron/X-Dron_lib
*/

#include "Timer_P.h"
#include <Arduino.h>

Timer_P::Timer_P()
{
  this->Old_Condition = false;
  this->Old_Reset = false;
  this->TimerRun = false;
  this->Old_TimerOut = false;
}

long Timer_P::GetRemains()
{
  return this->Remains;
}

void Timer_P::TimerV(boolean Condition, boolean Reset, int Mode, long Duration)
{
  boolean R_Condition = Condition && !(this->Old_Condition);
  boolean F_Condition = !Condition && this->Old_Condition;
  boolean R_Reset = Reset && !(this->Old_Reset);
  boolean F_Reset = !Reset && this->Old_Reset;
  boolean R_TimerOut;
  boolean F_TimerOut;
  
  if ((R_Condition && !Reset) && Mode < 3) this->TargetMsec = millis() + Duration;
  if ((R_Condition && !Reset) && Mode ==3 && !(this->TimerOut)) this->TargetMsec = millis() + Duration; 
  if ((F_Condition && !Reset) && Mode == 4)
     {
        this->TargetMsec = millis() + Duration;
        this->TimerRun = true;
     }
     
  if (Reset) 
   {
    this->TimerOut = false;
    this->TimerRun = false;
	this->Remains = Duration;
   }
  else
   {  
    switch (Mode) {
    case 0:
        if (R_Condition) 
        {
          this->TimerOut = true;
          this->TimerRun = true;
        }  
        if ((Condition && (millis() >  this->TargetMsec)) || !Condition)
        {
          this->TimerOut = false;
          this->TimerRun = false;
        }
        break;
    case 1:
        if (R_Condition)
        {
          this->TimerOut = true;
          this->TimerRun = true;
        }  
        if ((millis() >  this->TargetMsec))
        {
          this->TimerOut = false;
          this->TimerRun = false;
        }
        break;
    case 2:
        if (R_Condition) this->TimerRun = true; 
        if (Condition && (millis() >  this->TargetMsec) && this->TimerRun && !(this->TimerOut)) 
        {
          this->TimerOut = true;
          this->TimerRun = false;
        }
        if (!Condition)
        {
          this->TimerOut = false;
          this->TimerRun = false;
        }
        break;
    case 3:
        if (R_Condition) this->TimerRun = true; 
        if (this->TimerRun && (millis() >  this->TargetMsec)) 
        {
          this->TimerOut = true;
          this->TimerRun = false;
       }
        break;
    case 4:
        if (Condition || this->TimerRun) this->TimerOut = true;
        if (this->TimerRun && (millis() >  this->TargetMsec)) 
        {
          this->TimerOut = false;
          this->TimerRun = false;
		}		
        break;
    }
	F_TimerOut = this->Old_TimerOut && !(this->TimerOut);
	R_TimerOut = !(this->Old_TimerOut)&&(this->TimerOut);
	
	switch (Mode) {
	case 0:
	case 1:
		if (F_TimerOut) this->Remains = 0;
		if (!(this->TimerRun) && !Condition) this->Remains = Duration;
		break;
	case 2:
		if (R_TimerOut) this->Remains = 0;
		if (!(this->TimerRun) && !Condition) this->Remains = Duration;
	    break;
	case 3:
		if (R_TimerOut) this->Remains = 0;
		if (!(this->TimerRun) && !TimerOut) this->Remains = Duration;
	    break;
	case 4:
		if (!(this->TimerRun)) this->Remains = Duration;
	    break;
		}
	}
	if (this->TimerRun) this->Remains = this->TargetMsec - millis();
  
	this->Old_Condition = Condition;
	this->Old_Reset = Reset;
	this->Old_TimerOut = this->TimerOut;
}

boolean Timer_P::Timer(boolean Condition, boolean Reset, int Mode, long Duration)
{
	this->Timer_P::TimerV(Condition, Reset, Mode, Duration);
	return this->TimerOut;
}

boolean Timer_P::Q0()
{
	return this->TimerOut;
}