#include <SPI.h>
#include <Encoder_Buffer.h>

#define EncoderCS1 48
#define EncoderCS2 49

long encoder1Reading = 0;
long encoder2Reading = 0;

Encoder_Buffer Encoder1(EncoderCS1);
Encoder_Buffer Encoder2(EncoderCS2);

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(115200);
  SPI.begin();
  Encoder1.initEncoder();
  Encoder2.initEncoder();
}

void loop()
{
  encoder1Reading = Encoder1.readEncoder() / 4; //Read Encoder
  encoder2Reading = -Encoder2.readEncoder() / 4;
  Serial.print(encoder1Reading);
  Serial.print(",");
  Serial.println(encoder2Reading);

  delay(10);
}