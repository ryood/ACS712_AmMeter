// ACS712 AmMeter
// 2020.01.09
//
// ryood

#include <Arduino.h>
#include <U8g2lib.h>
#include <Wire.h>
#include <TimerOne.h>

#define SERIAL_TX (0)

#define VREF  (5000)       // 5V電源電圧(mV)
#define PWR_V_DIV (2)      // バッテリー電圧の分圧比
#define CALERT_MAX  (100)  // 警告音境界最大(mA)
#define CALERT_MIN  (-100) // 警告音境界最小(mA)

#define BUFFER_SIZE  (20)
#define DISPLAY_INTERVAL  (32)
#define PIN_BUZZER  (8)

U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);

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
  
#if (SERIAL_TX)  
  Serial.begin(9600);
#endif //(SERIAL_TX)
}

void loop()
{
  buffer0[bufferIndex] = analogRead(0);
  buffer1[bufferIndex] = analogRead(1);
  buffer2[bufferIndex] = analogRead(2);
  bufferIndex++;
  if (bufferIndex == BUFFER_SIZE) {
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

  /*
  // accuracy: 2mA
  c0 = (c0 + 1) >> 1 << 1;
  c1 = (c1 + 1) >> 1 << 1;
  */
  
  int pwrv = v2 * PWR_V_DIV;

  count++;
  if (count > DISPLAY_INTERVAL) {
    count = 0;

    // Alert Over Range
    if (c0 > CALERT_MAX || c0 < CALERT_MIN || c1 > CALERT_MAX || c1 < CALERT_MIN) {
      Timer1.initialize(200000);
      Timer1.attachInterrupt(beep);
    } else {
      Timer1.detachInterrupt();
    }
    
    // Write to OLED
    char strBuffer0[16];
    char strBuffer1[16];
    char strBuffer2[16];
    sprintf(strBuffer0, "%+04dmA", c0);
    sprintf(strBuffer1, "%+04dmA", c1);
    sprintf(strBuffer2, "BATT:%4dmV", pwrv);

    u8g2.clearBuffer();
    u8g2.setFont(u8g2_font_profont29_mf);
    u8g2.drawStr(0, 20, strBuffer0);
    u8g2.drawStr(0, 45, strBuffer1);
    u8g2.setFont(u8g2_font_profont17_mf);
    u8g2.drawStr(0, 64, strBuffer2);
    u8g2.sendBuffer();

#if (SERIAL_TX)
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
#endif //(SERIAL_TX)
  }
}
