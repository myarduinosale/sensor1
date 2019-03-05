#include "DHT.h"
float tempC;
int reading;

int tempPin = A2;
int led1Pin = 13;
int led2Pin = 12;
int ledRGB1 = 9;
int ledRGB2 = 10;
int ledRGB3 = 11;
int buzzerPin = 5;
DHT dht;

void setup()
{
  //Example By ArduinoAll
  pinMode(led1Pin, OUTPUT);
  pinMode(led2Pin, OUTPUT);
  pinMode(ledRGB1, OUTPUT);
  pinMode(ledRGB2, OUTPUT);
  pinMode(ledRGB3, OUTPUT);

  dht.setup(4);
  Serial.begin(9600);
  Serial.println("TEST By ArduinoAll.com");

}

void loop()
{

  // โค๊ด LM35 วัดอุณหภูมิแบบ Analog
  Serial.println("1 : Test LM35");
  for (int i = 0; i < 10; i++) {
    int val = analogRead(tempPin);
    float mv = ( val / 1024.0) * 5000;
    float cel = mv / 10;
    Serial.println(cel);
    delay(300);
  }

  // โค๊ด DHT11 วัดความชื้นและอุณหภูมิ
  Serial.println("2 : TEST DHT11");
  for (int i = 0; i < 5; i++) {
    float humidity = dht.getHumidity(); // วัดความชื้น
    float temperature = dht.getTemperature(); //  วัดอรณหภูมิ

    Serial.print(dht.getStatusString());
    Serial.print("\t");
    Serial.print(humidity, 1);
    Serial.print("\t\t");
    Serial.print(temperature, 1);
    Serial.print("\t\t");
    Serial.println(dht.toFahrenheit(temperature), 1);
    delay(2000);
  }

  Serial.println("3 : TEST LDR");
  for (int i = 0; i < 10; i++) {
    int val = analogRead(A1);
    Serial.println(val);
    delay(300);
  }


  Serial.println("4 : TEST Rotation VR");
  for (int i = 0; i < 10; i++) {
    int val = analogRead(A0);
    Serial.println(val);
    delay(300);
  }

  Serial.println("5 : TEST LED3+LED4");
  for (int i = 0; i < 10; i++) {
    Serial.println("LED Blue");
    digitalWrite(13, 1);
    digitalWrite(12, 0);
    delay(200);
    Serial.println("LED Red");
    digitalWrite(13, 0);
    digitalWrite(12, 1);
    delay(200);
  }
  digitalWrite(13, 0);
  digitalWrite(14, 0);

  Serial.println("6 : TEST LED RGB");
  digitalWrite(9, 1);
  digitalWrite(10, 0);
  digitalWrite(11, 0);
  delay(200);

  digitalWrite(9, 0);
  digitalWrite(10, 1);
  digitalWrite(11, 0);
  delay(200);

  digitalWrite(9, 0);
  digitalWrite(10, 0);
  digitalWrite(11, 1);
  delay(200);

  digitalWrite(9, 0);
  digitalWrite(10, 0);
  digitalWrite(11, 0);

  Serial.println("6 : TEST SW1+SW2 Press Button");
  int count = 0;
  do {
    if (digitalRead(2) == 0) {
      Serial.println("SW1 Press");
      count++;
      beep(50);
      delay(200);
    }
    if (digitalRead(3) == 0) {
      Serial.println("SW2 Press");
      count++;
      beep(50);
      delay(200);
    }
  } while (count < 4);
  Serial.println("Finish TEST press Reset to Test Again");
  delay(20000);
}


void beep(unsigned char delayms) {
  analogWrite(buzzerPin, 20);      // Almost any value can be used except 0 and 255
  // experiment to get the best tone
  delay(delayms);          // wait for a delayms ms
  analogWrite(buzzerPin, 0);       // 0 turns it off
  delay(delayms);          // wait for a delayms ms

}
