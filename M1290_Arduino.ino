   /*
  SHT30 Temperature & Humidity Sensor
  modified on 13 Oct 2020
  by Mohammad Reza Akbari @ Electropeak
  Home

  Based on Library Example
*/

#include "Wire.h"
#include "SHT31.h"

uint32_t start;
uint32_t stop;

SHT31 sht;

void setup()
{
  Serial.begin(115200);
  Wire.begin();

  sht.begin(0x44);    //Sensor I2C Address

  Wire.setClock(100000);
  uint16_t stat = sht.readStatus();
  Serial.print(stat, HEX);
  Serial.println();
}

void loop()
{
  sht.read();

  Serial.print("Temperature:");
  Serial.print(sht.getTemperature(), 1);
  Serial.print("\t");
  Serial.print("Humidity:");
  Serial.println(sht.getHumidity(), 1);
  delay(50);
}
