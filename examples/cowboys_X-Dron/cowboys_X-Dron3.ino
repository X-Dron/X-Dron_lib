    #include <DI.h>           
    #include <Timer_P.h>
    #define BUZZER_PIN   11  // пин с пищалкой
    #define PLAYER_COUNT 2  // количество игроков-ковбоев
    int buttonPins[PLAYER_COUNT] = {2, 3};
    int ledPins[PLAYER_COUNT] = {7, 8};
    boolean Tour, Win[PLAYER_COUNT];
    
    DI Keys[PLAYER_COUNT];  //создание массива из класса DI - дискретный вход 
    Timer_P KeyTimers[PLAYER_COUNT], LedTimers[PLAYER_COUNT], StartDelayTimer; //создание экземпляров таймеров
    
    void setup()
    {
      pinMode(BUZZER_PIN, OUTPUT);
      Tour = false;    // инициализация цикла игры
      for (int player = 0; player < PLAYER_COUNT; player++) {
        pinMode(ledPins[player], OUTPUT); //инициализация выходов на светодиоды
        Keys[player].Init(buttonPins[player], 10); //инициализация дискретных входов класса DI, антидребезг 10мс 
      }
    }
     
    void loop()
    {
      if (StartDelayTimer.Timer((!Tour), false, 2, random(3000, 8000))) // если тур игры не запущен, то через промежуток 3..8 секунд 
      {
        Tour = true;                     //запускаем тур
        tone(BUZZER_PIN, 3000, 250);     //даем сигнал 
      }
      for (int player = 0; player < PLAYER_COUNT; player++)
      {
         Keys[player].DI_Refresh();       //Обновляем входа
         Win[player] = KeyTimers[player].Timer(Keys[player].DI_Read(), !Tour, 0, 1); //Определяем победителя
         //Формируется импульс длительностью до 1мс по нажатию клавиш. 
         if (Win[player])   //Если победитель есть 
         {
           Tour = false;    //то тур завершился
           tone(BUZZER_PIN, 4000, 1500); //даем сигнал
         }
         digitalWrite(ledPins[player], LedTimers[player].Timer(Win[player], false, 1, 1500)); //обновляем светодиоды  
      }
    }
    

