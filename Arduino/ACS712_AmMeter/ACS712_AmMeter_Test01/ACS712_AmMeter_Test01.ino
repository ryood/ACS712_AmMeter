#define VREF  (4900)  // mV
#define BUFFER_SIZE  (32)

int buffer0[BUFFER_SIZE];
int buffer1[BUFFER_SIZE];
int bufferIndex = 0;

void setup()
{
  // リング・バッファを初期化
  for (int i = 0; i < BUFFER_SIZE; i++) {
    buffer0[i] = 512;
    buffer1[i] = 512;
  }
  
  Serial.begin(9600);
}

void loop()
{
  buffer0[bufferIndex] = analogRead(0);
  buffer1[bufferIndex] = analogRead(1);
  bufferIndex++;
  if (bufferIndex > BUFFER_SIZE) {
    bufferIndex = 0; 
  }
  long sum0 = 0;
  long sum1 = 0;
  for (int i = 0; i < BUFFER_SIZE; i++) {
    sum0 += buffer0[i];
    sum1 += buffer1[i];
  }

  long raw0 = sum0 / BUFFER_SIZE;
  long raw1 = sum1 / BUFFER_SIZE;
  
  int v0 = raw0 * VREF / 1024;
  int v1 = raw1 * VREF / 1024;
  
  int c0 = (v0 - 2500) / 5; 
  int c1 = (v1 - 2500) / 5;

  Serial.print(raw0);
  Serial.print('\t');
  Serial.print(raw1);
  Serial.print('\t');
  Serial.print(v0);
  Serial.print('\t');
  Serial.print(v1);
  Serial.print('\t');
  Serial.print(c0);
  Serial.print('\t');
  Serial.print(c1);
  Serial.println();

  //delay(100);
}
