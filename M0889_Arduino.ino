#include <Wire.h>
#include "SparkFunMPL3115A2.h"

MPL3115A2 myPressure;

void setup()
{
  Wire.begin();
  Serial.begin(9600);

  myPressure.begin();
  myPressure.setModeBarometer();
  myPressure.setOversampleRate(7);
  myPressure.enableEventFlags();
}

void loop()
{
  float pressure = myPressure.readPressure();
  Serial.print("ความกดอากาศ: ");
  Serial.print(pressure, 2);

  float temperature = myPressure.readTemp();
  Serial.print("  ค่าอุณหภูมิ: ");
  Serial.print(temperature, 2);
  Serial.print(" °C ");
  Serial.println();
}
