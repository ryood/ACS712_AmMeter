// 
// ADC0..2
// u8g2 full buffer
// 
#include <Arduino.h>
#include <U8g2lib.h>
#include <Wire.h>
#include <TimerOne.h>

U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);

#define VREF  (4900)  // mV
#define PWR_V_DIV (2) // 電源電圧の分圧比
#define BUFFER_SIZE  (16)
#define DISPLAY_INTERVAL  (32)
#define PIN_BUZZER  (8)

int buffer0[BUFFER_SIZE];
int buffer1[BUFFER_SIZE];
int buffer2[BUFFER_SIZE];
int bufferIndex = 0;

int count = 0;

void beep()
{
  tone(PIN_BUZZER, 1000, 50);
}

void setup()
{
  // リング・バッファを初期化
  for (int i = 0; i < BUFFER_SIZE; i++) {
    buffer0[i] = 512;
    buffer1[i] = 512;
    buffer2[i] = 512;
  }
  u8g2.begin();
  Serial.begin(9600);
}

void loop()
{
  buffer0[bufferIndex] = analogRead(0);
  buffer1[bufferIndex] = analogRead(1);
  buffer2[bufferIndex] = analogRead(2);
  bufferIndex++;
  if (bufferIndex > BUFFER_SIZE) {
    bufferIndex = 0; 
  }
  long sum0 = 0;
  long sum1 = 0;
  long sum2 = 0;
  for (int i = 0; i < BUFFER_SIZE; i++) {
    sum0 += buffer0[i];
    sum1 += buffer1[i];
    sum2 += buffer2[i];
  }

  long raw0 = sum0 / BUFFER_SIZE;
  long raw1 = sum1 / BUFFER_SIZE;
  long raw2 = sum2 / BUFFER_SIZE;
    
  int v0 = raw0 * VREF / 1024;
  int v1 = raw1 * VREF / 1024;
  int v2 = raw2 * VREF / 1024;
  
  int c0 = -(v0 - 2500) / 5; 
  int c1 = -(v1 - 2500) / 5;
  int pwrv = v2 * PWR_V_DIV;

  count++;
  if (count > DISPLAY_INTERVAL) {
    count = 0;

    // Alert Over Range
    if (c0 > 450 || c0 < -450 || c1 > 450 || c1 < -450) {
      Timer1.initialize(200000);
      Timer1.attachInterrupt(beep);
    } else {
      Timer1.detachInterrupt();
    }
    
    // Write to OLED
    char strBuffer0[16];
    char strBuffer1[16];
    sprintf(strBuffer0, "%+04dmA", c0);
    sprintf(strBuffer1, "%+04dmA", c1);

/* page buffer
    u8g2.firstPage();
    do {
      u8g2.setFont(u8g2_font_inb21_mf);
      u8g2.drawStr(0, 32, strBuffer0);
      u8g2.drawStr(0, 64, strBuffer1);
    } while (u8g2.nextPage());
*/

    u8g2.clearBuffer();
    u8g2.setFont(u8g2_font_inb21_mf);
    u8g2.drawStr(0, 32, strBuffer0);
    u8g2.drawStr(0, 64, strBuffer1);
    u8g2.sendBuffer();

/*
    // Write to Serial
    Serial.print(raw0);
    Serial.print('\t');
    Serial.print(raw1);
    Serial.print('\t');
    Serial.print(raw2);
    Serial.print('\t');
    Serial.print(v0);
    Serial.print('\t');
    Serial.print(v1);
    Serial.print('\t');
    Serial.print(v2);
    Serial.print('\t');
    Serial.print(c0);
    Serial.print('\t');
    Serial.print(c1);
    Serial.print('\t');
    Serial.print(pwrv);
    Serial.println();
*/
  }
}
