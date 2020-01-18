#include <TimerOne.h>

#define PIN_BUZZER  (10)

void beep()
{
  tone(PIN_BUZZER, 1000, 50);
}

void setup()
{
  Timer1.initialize(500000);
  Timer1.attachInterrupt(beep);
}

void loop()
{
}
