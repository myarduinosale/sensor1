#include <Wire.h>
#include <Adafruit_AM2315.h>
// Connect RED of the AM2315 sensor to 5.0V
// Connect BLACK to Ground
// Connect WHITE to i2c clock - on '168/'328 Arduino Uno/Duemilanove/etc thats Analog 5
// Connect YELLOW to i2c data - on '168/'328 Arduino Uno/Duemilanove/etc thats Analog 4
void setup() {
  Serial.begin(9600);
  Serial.println("AM2315 Test!");

  if (! am2315.begin()) {
     Serial.println("Sensor not found, check wiring & pullups!");
     while (1);
  }
}

void loop() {
  Serial.print("Hum: "); 
  Serial.println(am2315.readHumidity());
  Serial.print("Temp: "); 
  Serial.println(am2315.readTemperature());

  delay(1000);
}
