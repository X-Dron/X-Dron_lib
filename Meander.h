/*
* Project: X-Dron_library/Arduino Library
* Library class: Meander
* Author: X-Dron, X-Dron@mail.ru
* Copyright: (C) 2015 by X-Dron
* License: GNU GPL v3 (see License.txt)
* Web: https://github.com/X-Dron/X-Dron_lib
*/
#ifndef Meander_h
#define Meander_h
#include <Arduino.h>
#include "Timer_P.h"

class Meander
{
private:
  boolean PulseB;
  long period_msc;
public:
  //Meander();
  void MeanderV(long Period, long Pulse);
  boolean MeanderB(long Period, long Pulse);
  boolean Q0();
};
#endif