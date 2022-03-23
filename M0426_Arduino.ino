#include "Arduino.h"
#include <DHT12.h>

DHT12 dht12;

void setup()
{
  Serial.begin(112560);
  dht12.begin();
}
int timeSinceLastRead = 0;

void loop()
{
  if(timeSinceLastRead > 2000) {

    float t12 = dht12.readTemperature();
    float f12 = dht12.readTemperature(true);
    float h12 = dht12.readHumidity();

    bool dht12Read = true;
    if (isnan(h12) || isnan(t12) || isnan(f12)) {
      Serial.println("Failed to read from DHT12 sensor!");

      dht12Read = false;
    }

    if (dht12Read){
      float hif12 = dht12.computeHeatIndex(f12, h12);
      float hic12 = dht12.computeHeatIndex(t12, h12, false);
      float dpf12 = dht12.dewPoint(f12, h12);
      float dpc12 = dht12.dewPoint(t12, h12, false);


      Serial.print("ค่าความชื้น: ");
      Serial.print(h12);
      Serial.print(" %\t");
      Serial.print("ค่าอุณหภูมิ: ");
      Serial.print(t12);
      Serial.print(" *C ");
      Serial.print(f12);
      Serial.println(" *F\t");

    }
    timeSinceLastRead = 0;
  }
  delay(100);
  timeSinceLastRead += 100;

}
