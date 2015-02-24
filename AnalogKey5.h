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

class AnalogKey5 // ��������� �����
    {
private:
  boolean Value[5];  //�������� ������� ������ 
  int Base[5];       //������� �������� ����������� �������
  int DeadZone;   //������ ���� ���������� ��������
  Timer_P Filtr_On[5], Filtr_Off[5]; //������� ���������� "��������" 
public:
  AnalogKey5(int Base1, int Base2, int Base3, int Base4, int Base5, int DeadZone); //����������� ������ ��� �������� ������� �������� ������� �������� � ������ ����
  boolean Key1(); //���������� ��������� Value[0]
  boolean Key2(); //���������� ��������� Value[1]
  boolean Key3(); //���������� ��������� Value[2]
  boolean Key4(); //���������� ��������� Value[3]
  boolean Key5(); //���������� ��������� Value[4]
  void Refresh(int aValue); //��������� ��������� "����������" ������ �� ���������� ��������  
};
#endif