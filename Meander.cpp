/*
* Project: X-Dron_library/Arduino Library
* Library class: Meander
* Author: X-Dron, X-Dron@mail.ru
* Copyright: (C) 2015 by X-Dron
* License: GNU GPL v3 (see License.txt)
* Web: https://github.com/X-Dron/X-Dron_lib
*/

#include "Meander.h"
#include <Arduino.h>

void Meander::MeanderV(long Period, long Pulse)
{
    this->period_msc = millis() % Period;
	if (this->period_msc < Pulse) this->PulseB = true;
	else this->PulseB = false;
}

boolean Meander::Q0()
{
	return this->PulseB;
}

 boolean Meander::MeanderB(long Period, long Pulse)
 {
	this->Meander::MeanderV(Period, Pulse);
	return this->PulseB;
 }
 