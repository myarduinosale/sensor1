#include <Arduino.h>
#include "SHTC3.h"
 
SHTC3 s(Wire);
 
void setup() {
Serial.begin(9600);
Wire.begin();
}
 
void loop() {
s.begin(true);
s.sample();
Serial.print("อุณหภูมิ ");
Serial.print(s.readTempC());
Serial.print(" °C    ความชื้น ");
Serial.print(s.readHumidity());
Serial.println(" %");
delay(2000);
}
