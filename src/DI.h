/*
* Project: X-Dron_library/Arduino Library
* Library class: DI
* Author: X-Dron, X-Dron@mail.ru
* Copyright: (C) 2015 by X-Dron
* License: GNU GPL v3 (see License.txt)
* Web: https://github.com/X-Dron/X-Dron_lib
*/
#ifndef DI_h
#define DI_h
#include <Arduino.h>
#include "Timer_P.h"

class DI
{
private:
  boolean DI_Value;
  int PIN;
  Timer_P DI_Filtr_On, DI_Filtr_Off;
  long Filtr_Duration;
public:
  DI();
  DI(int PIN, long Duration);
  void Init(int PIN, long Duration);
  boolean DI_Read();
  void DI_Refresh();
};
#endif