#include <Wire.h>
#include "Seeed_BME280.h"
#include "Adafruit_Si7021.h"

Adafruit_Si7021 sensor = Adafruit_Si7021();
BME280 bme280;

void setup()
{
  Serial.begin(9600);
  Serial.println("ArduinoAll Example GY-21p Test");

  if (!bme280.init()) { // เช็คว่าเซนเซอร์ ความกดอากาศ BMP280 ทำงาน
    Serial.println("Device error!");
  }

  if (!sensor.begin()) // เช็คว่าเซนเซอร์ อุณหภูมิและความชื้น Si7021 ทำงาน
  {
    Serial.println("Did not find Si7021 sensor!");
    while (true);
  }
}

void loop()
{
  /// การใช้งานเซนเซอร์ BMP280
  float pressure;
  //ดึงค่าอุณหภูมิ
  Serial.print("Temp: ");
  Serial.print(bme280.getTemperature()); // ดึงค่าอุณหภูมิ
  Serial.println("C");

  //ดึงค่าความกดอากาศ
  Serial.print("Pressure: ");
  Serial.print(pressure = bme280.getPressure());
  Serial.println("Pa");

  //ดึงค่า altitude data
  Serial.print("Altitude: ");
  Serial.print(bme280.calcAltitude(pressure));
  Serial.println("m");

  Serial.println("SI7021 results");
  Serial.print("Humidity: ");
  Serial.println(sensor.readHumidity(), 2);
  Serial.print("Temperature: ");
  Serial.println(sensor.readTemperature(), 2);
  Serial.println();
  delay(2000);
}
