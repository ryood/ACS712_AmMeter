#define PIN_BUZZER  (8)

void setup() {
  // put your setup code here, to run once:

}

void loop()
{
  for (;;) {
    tone(PIN_BUZZER, 2000);
    delay(100);
    noTone(PIN_BUZZER);
    delay(400);
  }
}
