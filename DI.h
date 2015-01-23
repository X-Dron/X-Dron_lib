#ifndef DI_h
#define DI_h
#include <Arduino.h>
#include "Timer_P.h"

/* DI library 
MIT license
written by X-Dron
*/

class DI
{
private:
  boolean DI_Value;
  int PIN;
  Timer_P DI_Filtr_On, DI_Filtr_Off;
  long Filtr_Duration;
public:
  DI(int PIN, long Duration);
  boolean DI_Read();
  void DI_Refresh();
};
#endif