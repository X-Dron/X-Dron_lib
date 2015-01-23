#include "DI.h"
#include <Arduino.h>

DI::DI(int PIN, long Duration)
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
  if (this->DI_Filtr_On.Timer_P::Timer(not digitalRead(this->PIN), 0, 2, this->Filtr_Duration)) this->DI_Value = 1;
  if (this->DI_Filtr_Off.Timer_P::Timer(digitalRead(this->PIN), 0, 2, this->Filtr_Duration)) this->DI_Value = 0;
}