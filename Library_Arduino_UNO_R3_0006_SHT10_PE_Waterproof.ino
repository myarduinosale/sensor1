#include <SHT1x.h>

#define dataPin  10
#define clockPin 11
SHT1x sht1x(dataPin, clockPin);

int ledPin = 2;
int ledPin3 = 3;
int analogPin = 5;
int val = 0;
void setup()
{
  pinMode(ledPin, OUTPUT); // sets the pin as output
  pinMode(ledPin3, OUTPUT); // sets the pin as output
  Serial.begin(38400); // Open serial connection to report values to host
  Serial.println("Starting up");
}

void loop()
{
  float temp_c; // ค่าอุณหภูมิ ที่แสดงหน่วยเป็น องศาเซลเซียส
  float temp_f; // ค่าอุณหภูมิ ที่แสดงหน่วยเป็น องศาฟาเรนไฮต์
  float humidity; // ค่าความชื้น

  temp_c = sht1x.readTemperatureC();
  temp_f = sht1x.readTemperatureF();
  humidity = sht1x.readHumidity();

  Serial.print("Temperature: ");
  Serial.print(temp_c, DEC);
  Serial.print("C / ");
  Serial.print(temp_f, DEC);
  Serial.print("F. Humidity: ");
  Serial.print(humidity);
  Serial.println("%");
  if (temp_c < 25  ) { // ค่าที่กำหนดไว้เพื่อให้วงจร LED ทำงาน ในที่นี้กำหนดการทำงานเมื่อค่าอุณหภูมิ ที่แสดงหน่วยเป็น องศาเซลเซียส ต่ำกว่า 25
    digitalWrite(ledPin, LOW); // สั่งให้ LED ที่ Pin2 ดับ
    digitalWrite(ledPin3, HIGH); // สั่งให้ LED ที่ Pin3 ติดสว่าง
  }
  else {
    digitalWrite(ledPin, HIGH); // สั่งให้ LED ที่ Pin2 ติดสว่าง
    digitalWrite(ledPin3, LOW); // สั่งให้ LED ที่ Pin3 ดับ

  }
  delay(100);
}
