#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define OLED_RESET 16
Adafruit_SSD1306 display(OLED_RESET);

int RelayD5 = D5; // ขา D5
int RelayD6 = D6; // ขา D6
int RelayD7 = D7; // ขา D7
int RelayD8 = D8; // ขา D8

void setup() {
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C); //สั่งให้จอ OLED เริ่มทำงานที่ Address 0x3C
  display.clearDisplay(); // ลบภาพในหน้าจอทั้งหมด
  display.setTextSize(1); // กำหนดขนาดตัวอักษร
  display.setTextColor(WHITE);
  display.setCursor(0, 0); // กำหนดตำแหน่ง x,y ที่จะแสดงผล
  display.println(" OLED 0.96 TESTER ");
  display.setCursor(4, 10);
  display.setTextSize(2);
  display.setTextColor(BLACK, WHITE); //กำหนดข้อความสีขาว ฉากหลังสีดำ
  display.println("Cybertice");
  display.setCursor(0, 32);
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.println("128 x 64 Pixels 0.96");
  display.setCursor(0, 48);
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.println("  www.Cybertice.com "); // แสดงผลข้อความ www.Myarduino.net
  display.display();

  pinMode(RelayD5, OUTPUT);
  pinMode(RelayD6, OUTPUT);
  pinMode(RelayD7, OUTPUT);
  pinMode(RelayD8, OUTPUT);

  digitalWrite(RelayD5, LOW);
  digitalWrite(RelayD6, LOW);
  digitalWrite(RelayD7, LOW);
  digitalWrite(RelayD8, LOW);
}
void loop() {
  digitalWrite(RelayD5, HIGH);
  digitalWrite(RelayD6, HIGH);
  digitalWrite(RelayD7, HIGH);
  digitalWrite(RelayD8, HIGH);
  delay(300);
  digitalWrite(RelayD5, LOW);
  digitalWrite(RelayD6, LOW);
  digitalWrite(RelayD7, LOW);
  digitalWrite(RelayD8, LOW);
  delay(300);
}
