#include "DHT.h"
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
int Number = 0;
const int in3Pin = 3;
const int in4Pin = 4;
int p8_Lv1 = 8;
int p8_Lv2 = 9;
int p8_Lv3 = 10;
int p8_Lv4 = 11;
LiquidCrystal_I2C lcd(0x27, 16, 2);
#define DHTPIN 2     // what digital pin we're connected to
#define DHTTYPE DHT22   // DHT 22  (AM2302), AM2321
DHT dht(DHTPIN, DHTTYPE);
void setup() {
  Serial.begin(9600);
  Serial.println("DHTxx test!");
  dht.begin();
  lcd.begin();
  lcd.backlight();
  pinMode(in3Pin, OUTPUT);
  pinMode(in4Pin, OUTPUT);
  analogWrite (in3Pin , 0);
  digitalWrite(in4Pin, LOW);
  pinMode(p8_Lv1, OUTPUT);
  pinMode(p8_Lv2, OUTPUT);
  pinMode(p8_Lv3, OUTPUT);
  pinMode(p8_Lv4, OUTPUT);
  digitalWrite(p8_Lv1, LOW);
  digitalWrite(p8_Lv2, LOW);
  digitalWrite(p8_Lv3, LOW);
  digitalWrite(p8_Lv4, LOW);
}
void loop() {
  delay(2000);
  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
  float f = dht.readTemperature(true);
  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
  // Compute heat index in Fahrenheit (the default)
  float hif = dht.computeHeatIndex(f, h);
  // Compute heat index in Celsius (isFahreheit = false)
  float hic = dht.computeHeatIndex(t, h, false);
  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.print(" %\t");
  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.print(" *C ");
  Serial.print(f);
  Serial.print(" *F\t");
  Serial.print("Heat index: ");
  Serial.print(hic);
  Serial.print(" *C ");
  Serial.print(hif);
  Serial.println(" *F");
  if ( t < 30 ) {
    Number = 0;
    analogWrite (in3Pin , 0);
    digitalWrite(p8_Lv1, LOW);
    digitalWrite(p8_Lv2, HIGH);
    digitalWrite(p8_Lv3, HIGH);
    digitalWrite(p8_Lv4, HIGH);
  }
  if ( t > 30 && t <= 35 ) {
    Number = 1;
    analogWrite (in3Pin , 255);
    digitalWrite(p8_Lv1, LOW);
    digitalWrite(p8_Lv2, LOW);
    digitalWrite(p8_Lv3, HIGH);
    digitalWrite(p8_Lv4, HIGH);
  }
  if ( t > 35 && t <= 40 ) {
    Number = 2;
    analogWrite (in3Pin , 127);
    digitalWrite(p8_Lv1, LOW);
    digitalWrite(p8_Lv2, LOW);
    digitalWrite(p8_Lv3, LOW);
    digitalWrite(p8_Lv4, HIGH);
  }
  if ( t > 40  ) {
    Number = 3;
    analogWrite (in3Pin , 255);
    digitalWrite(p8_Lv1, LOW);
    digitalWrite(p8_Lv2, LOW);
    digitalWrite(p8_Lv3, LOW);
    digitalWrite(p8_Lv4, LOW);
  }
  lcd.setCursor(0, 0);
  lcd.print("Tem:");
  lcd.print(t);
  lcd.print("*C");
  lcd.setCursor(0, 1);
  lcd.print("Hum:");
  lcd.print(h);
  lcd.print("% ");
  lcd.print("Num:");
  lcd.print(Number);
}
