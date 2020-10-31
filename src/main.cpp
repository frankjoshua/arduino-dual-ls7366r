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
  Serial.begin(9600);
  SPI.begin();
  Encoder1.initEncoder();
  Encoder2.initEncoder();
}

void loop()
{
  encoder1Reading = Encoder1.readEncoder(); //Read Encoder
  encoder2Reading = -Encoder2.readEncoder();
  Serial.print(encoder1Reading);
  Serial.print(",");
  Serial.println(encoder2Reading);
  //Encoder1.clearEncoderCount();// Clear Encoder
}