/*
* Project: X-Dron_library/Arduino Library
* Library class: AnalogKey5
* Author: X-Dron, X-Dron@mail.ru
* Copyright: (C) 2015 by X-Dron
* License: GNU GPL v3 (see License.txt)
* Web: https://github.com/X-Dron/X-Dron_lib
*/
#ifndef AnalogKey5_h
#define AnalogKey5_h
#include <Arduino.h>
#include "Timer_P.h"

class AnalogKey5 // описываем класс
    {
private:
  boolean Value[5];  //Значение нажатой кнопки 
  int Base[5];       //Базовое значение аналогового сигнала
  int DeadZone;   //Ширина зоны допустимых значений
  Timer_P Filtr_On[5], Filtr_Off[5]; //Таймеры фильтрации "дребезга" 
public:
  AnalogKey5(int Base1, int Base2, int Base3, int Base4, int Base5, int DeadZone); //Конструктор класса при создании объекта задается базовое значение и ширина зоны
  boolean Key1(); //возвращает состояние Value[0]
  boolean Key2(); //возвращает состояние Value[1]
  boolean Key3(); //возвращает состояние Value[2]
  boolean Key4(); //возвращает состояние Value[3]
  boolean Key5(); //возвращает состояние Value[4]
  void Refresh(int aValue); //обновляет состояние "Аналоговой" кнопки по считанному значению  
};
#endif