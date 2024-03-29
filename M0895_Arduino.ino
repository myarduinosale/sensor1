#include <SHT21.h> // include SHT21 library

SHT21 sht;

float temp; // variable to store temperature
float humidity; // variable to store hemidity

void setup() {
  Wire.begin(); // begin Wire(I2C)
  Serial.begin(9600); // begin Serial
}

void loop() {

  temp = sht.getTemperature(); // get temp from SHT
  humidity = sht.getHumidity(); // get temp from SHT

  Serial.print("อุณหภูมิ: "); // print readings
  Serial.print(temp);
  Serial.print("  ความชื้น: ");
  Serial.println(humidity);

  delay(85); // min delay for 14bit temp reading is 85ms
}
