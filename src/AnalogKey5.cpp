/*
* Project: X-Dron_library/Arduino Library
* Library class: AnalogKey5
* Author: X-Dron, X-Dron@mail.ru
* Copyright: (C) 2015 by X-Dron
* License: GNU GPL v3 (see License.txt)
* Web: https://github.com/X-Dron/X-Dron_lib
*/
#include "AnalogKey5.h"
#include <Arduino.h>

AnalogKey5::AnalogKey5(int Base1, int Base2, int Base3, int Base4, int Base5, int DeadZone)
{
  this->Base[0] = Base1;
  this->Base[1] = Base2;
  this->Base[2] = Base3;
  this->Base[3] = Base4;
  this->Base[4] = Base5;      
  this->DeadZone =DeadZone;
}

boolean AnalogKey5::Key1()
{
  return this->Value[0];
}

boolean AnalogKey5::Key2()
{
  return this->Value[1];
}
    
boolean AnalogKey5::Key3()
{
  return this->Value[2];
}
    
boolean AnalogKey5::Key4()
{
  return this->Value[3];
}
    
boolean AnalogKey5::Key5()
{
  return this->Value[4];
}
    
void AnalogKey5::Refresh(int aValue)
{
  for (int i=0; i<5; i++)
  {
    if (this->Filtr_On[i].Timer_P::Timer ( ((aValue >= Base[i]-DeadZone)&&(aValue <= Base[i]+DeadZone)), 0, 2, 50)) this->Value[i] = 1;
    if (this->Filtr_Off[i].Timer_P::Timer(!((aValue >= Base[i]-DeadZone)&&(aValue <= Base[i]+DeadZone)), 0, 2, 50)) this->Value[i] = 0;
  }
}