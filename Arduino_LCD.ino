#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
void setup() {
  lcd.begin(16, 2); // กำหนดเชื่อมต่อจอ 16ตัวอักษร 2 แถว

}
void loop() {
  lcd.setCursor(0, 0); // กำหนดให้ เคอร์เซอร์ อยู่ตัวอักษรตำแหน่งที่0 แถวที่ 1 เตรียมพิมพ์ข้อความ
  lcd.print("I Love Myarduino"); //พิมพ์ข้อความ "I Love Myarduino"
  lcd.setCursor(2, 1); // กำหนดให้ เคอร์เซอร์ อยู่ตัวอักษรกำแหน่งที3 แถวที่ 2 เตรียมพิมพ์ข้อความ
  lcd.print("myarduino.net"); //พิมพ์ข้อความ "myarduino.net"
}
