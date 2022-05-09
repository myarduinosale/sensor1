#include <Wire.h>
#include <LiquidCrystal_I2C.h>
 
// Set the LCD address to 0x27 or 0x3F for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 40, 2);
 
void setup()
{
// initialize the LCD
lcd.begin();
 
// Turn on the blacklight and print a message.
lcd.backlight();
lcd.setCursor(9, 0); // ไปที่ตัวอักษรที่ 9 แถวที่ 1
lcd.print("Welcome To CyberTice");
 
lcd.setCursor(11, 1); // ไปที่ตัวอักษรที่ 11 แถวที่ 2
lcd.print("www.cybertice.com");
 
}
void loop() {
 
}
