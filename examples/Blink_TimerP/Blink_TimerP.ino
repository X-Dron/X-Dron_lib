    #include <Timer_P.h>     //подключаем библиотеку Timer_P - работа с таямерами из набора библиотек от X-Dron
    #define LED_PIN 7        //PIN светодиода
    #define Period 2000      //Период меандра
    #define Duration 500    //Импульс меандра
    
    Timer_P Period_T, Pulse_T;   //создание и инициализация объекта Timer_Test класса Timer_P

    void setup() {
      //Режимы выходов 
      pinMode(LED_PIN, OUTPUT);
    }
    
    void loop() {
      Period_T.TimerV(!Period_T.Q0(), 0, 2, Period); // Самосбрасывающийся таймер периода
      Pulse_T.TimerV(!Period_T.Q0(), 0, 1, Duration);// Импульс длительности Duration по началу периода
      //Выводим меандр на лампочку.
      digitalWrite(LED_PIN, Pulse_T.Q0());
  
    }
