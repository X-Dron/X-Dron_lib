    #include <DI.h>         //подключаем библиотеку DI - обработка дискретного входа из набора библиотек от X-Dron  
    #include <Timer_P.h>    //подключаем библиотеку Timer_P - работа с таямерами из набора библиотек от X-Dron
    #include <TM1637.h>     //подключаем библиотеку цифрового четырехзначного индикатора 
    
    #define DISPLAY_CLK_PIN 12  //PIN контакта CLK индикатора 
    #define DISPLAY_DIO_PIN 13  //PIN контакта DIO индикатора
    #define Condition_PIN 2     //PIN кнопки условия работы таймера 
    #define Reset_PIN 3         //PIN кнопки сброса таймера
    #define QTimer_PIN 7        //PIN светодиода работы таймера
    #define QReset_PIN 8        //PIN светодиода сброса таймера
    
    TM1637 display(DISPLAY_CLK_PIN, DISPLAY_DIO_PIN);  //создание и инициализация объекта display класса TM1637
    Timer_P Timer_Test;                                //создание и инициализация объекта Timer_Test класса Timer_P
    // Создание объектов типа "Дистретный вход" они посажены описанные выше пины. Фильтр антидребезга 30мс.
    DI Condition_IN(Condition_PIN, 30);              
    DI Reset_IN(Reset_PIN, 30);
    
    void setup() {
      //Режимы выходов 
      pinMode(QTimer_PIN, OUTPUT);
      pinMode(QReset_PIN, OUTPUT);     
      //Включаем и настраиваем индикатор
      display.set();
      display.init();
      //делать pinMode для входов не нужно. Они инициализируются при создании объекта класса DI
      //при работе со входами используется INPUT_PULLUP-режим. Значения входов нормализовываются во время обработки класса.
      //замкнутая кнопка - логическая 1. 
    }
    
    void loop() {
      // Обновляем значение дискретных входов
      // Производится их считывание с пинов и фильтрация через внутреннюю переменную класса. 
      Condition_IN.DI_Refresh();
      Reset_IN.DI_Refresh();
      
      //Считываем состояние фильтрованной кнопки сброса таймера и выводим его на лампочку.
      digitalWrite(QReset_PIN, Reset_IN.DI_Read());
      
      //Запускаем таймер по фильтрованной кнопке запуска таймера.
      //Сброс выполнения таймера по фильтрованной кнопке сброса таймера.
      //Режим работы таймера - Mode = 1 extended pulse 
      //Время работы таймера - 1900мс.
      //Результат работы таймера выводим на светодиод работы таймера 
      digitalWrite(QTimer_PIN, Timer_Test.Timer(Condition_IN.DI_Read(), Reset_IN.DI_Read(), 1, 1900));
      
      //Получаем значение отсрочки срабатывания таймера
      long T_Remains = Timer_Test.GetRemains();
      
      //Значения для отображения на каждом из 4 разрядов
      int8_t Disp[4];
      //Выводим значение отсрочки срабатывания таймера на дисплей
      Disp[0] = T_Remains/1000;
      Disp[1] = (T_Remains/100)%10;
      Disp[2] = (T_Remains/10)% 10;
      Disp[3] = T_Remains% 10;
      display.display(Disp);
    }
