// ACS712 AmMeter
// 2020.02.07
//
// ryood

#include <Arduino.h>
#include <U8g2lib.h>
#include <Wire.h>
#include <TimerOne.h>

#define SERIAL_TX (0)

#define DISPLAY_CURRENT (0)
#define DISPLAY_VOLTAGE (1)
#define DISPLAY_RAW     (2)
#define DISPLAY_MODE    (DISPLAY_CURRENT)

// Analog Pins
#define PIN_VBAT   (1)
#define PIN_VPOS   (2)
#define PIN_VNEG   (3)

// Digital Pins
#define PIN_BUZZER  (11)
#define PIN_CAL_SW  (2)

#define VREF  (5125)       // 5V電源電圧(mV)
#define PWR_V_DIV (0.5f)   // バッテリー電圧の分圧比
#define CALERT_MAX  (400)  // 警告音境界最大(mA)
#define CALERT_MIN  (-400) // 警告音境界最小(mA)

#define BUFFER_SIZE  (20)
#define DISPLAY_INTERVAL  (32)

U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);

int buffer0[BUFFER_SIZE];
int buffer1[BUFFER_SIZE];
int buffer2[BUFFER_SIZE];
int bufferIndex = 0;

int biasPositive = 0;
int biasNegative = 0;

int count = 0;

void readValue(long *raw0, long *raw1, long *raw2)
{
  buffer0[bufferIndex] = analogRead(PIN_VPOS);
  buffer1[bufferIndex] = analogRead(PIN_VNEG);
  buffer2[bufferIndex] = analogRead(PIN_VBAT);
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

  *raw0 = sum0 / BUFFER_SIZE;
  *raw1 = sum1 / BUFFER_SIZE;
  *raw2 = sum2 / BUFFER_SIZE;
}

void calibration()
{
  long raw0;
  long raw1;
  long raw2;

  for (int i = 0; i < BUFFER_SIZE; i++) {
    readValue(&raw0, &raw1, &raw2);
  }

  biasPositive = 512 - raw0;
  biasNegative = 512 - raw1;
}

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

  pinMode(PIN_CAL_SW, INPUT_PULLUP);
  
  u8g2.begin();
  //u8g2.setFlipMode(1);
  
#if (SERIAL_TX)  
  Serial.begin(9600);
#endif //(SERIAL_TX)
}

void loop()
{
  if (digitalRead(PIN_CAL_SW) == LOW) {
    calibration();
  }
  
  long raw0;
  long raw1;
  long raw2;
  
  readValue(&raw0, &raw1, &raw2);
    
  int v0 = ((raw0 + biasPositive) * VREF / 1024);
  int v1 = ((raw1 + biasNegative) * VREF / 1024);
  int v2 = raw2 * VREF / 1024;
  
  int c0 = -(v0 - (VREF / 2)) / 5; 
  int c1 = -(v1 - (VREF / 2)) / 5;
  int pwrv = v2 / PWR_V_DIV;

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

#if (DISPLAY_MODE == DISPLAY_CURRENT)
    sprintf(strBuffer0, "%+04dmA", c0);
    sprintf(strBuffer1, "%+04dmA", c1);
    sprintf(strBuffer2, "%4dmV %+3d %+3d", pwrv, biasPositive, biasNegative);
#elif (DISPLAY_MODE == DISPLAY_VOLTAGE)
    //読み取り電圧表示
    sprintf(strBuffer0, "%d", v0);
    sprintf(strBuffer1, "%d", v1);
    sprintf(strBuffer2, "%d %d %d", v2, biasPositive, biasNegative);
#else
    //読み取り直値表示
    sprintf(strBuffer0, "%d", raw0);
    sprintf(strBuffer1, "%d", raw1);
    sprintf(strBuffer2, "%d %d %d", raw2, biasPositive, biasNegative);
#endif
    
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
