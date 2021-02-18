#include <Wire.h>
#include "AHT20.h"

AHT20 AHT;

void setup()
{
  Serial.begin(115200);
  Serial.println("AHT20 DEMO");
  AHT.begin();
}

void loop()
{
  float humi, temp;

  int ret = AHT.getSensor(&humi, &temp);

  if (ret) // GET DATA OK
  {
    Serial.print("humidity: ");
    Serial.print(humi * 100);
    Serial.print("%\t temperature: ");
    Serial.println(temp);
  }
  else // GET DATA FAIL
  {
    Serial.println("GET DATA FROM ATH20 FAIL");
  }

  delay(100);
}
