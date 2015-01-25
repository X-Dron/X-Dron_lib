/*
* Project: X-Dron_library/Arduino Library
* Library class: DI
* Author: X-Dron, X-Dron@mail.ru
* Copyright: (C) 2015 by X-Dron
* License: GNU GPL v3 (see License.txt)
* Web: https://github.com/X-Dron/X-Dron_lib
*/
#include "DI.h"
#include <Arduino.h>

DI::DI()
{
}

DI::DI(int PIN, long Duration)
{
  pinMode(PIN, INPUT_PULLUP);
  this->Filtr_Duration = Duration;
  this->PIN =PIN;
}

void DI::Init(int PIN, long Duration)
{
  pinMode(PIN, INPUT_PULLUP);
  this->Filtr_Duration = Duration;
  this->PIN =PIN;
}

boolean DI::DI_Read()
{
  return this->DI_Value;
}

void DI::DI_Refresh()
{
  if (this->DI_Filtr_On.Timer_P::Timer(!digitalRead(this->PIN), 0, 2, this->Filtr_Duration)) this->DI_Value = 1;
  if (this->DI_Filtr_Off.Timer_P::Timer(digitalRead(this->PIN), 0, 2, this->Filtr_Duration)) this->DI_Value = 0;
}