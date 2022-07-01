#include <Wire.h>
#include <Thinary_AHT_Sensor.h>

AHT_Sensor_Class AHT10;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Wire.begin();
  if (AHT10.begin(eAHT_SensorAddress_Low))
    Serial.println("Init AHT10 Sucess.");
  else
    Serial.println("Init AHT10 Failure.");
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("ความชื้น:  ");
  Serial.print(AHT10.GetHumidity());
  Serial.println(" %");
  Serial.print("อุณหภูมิ:  ");
  Serial.print(AHT10.GetTemperature());
  Serial.println(" ℃");
  Serial.println();
  delay(500);
}
