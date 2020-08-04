#include <Wire.h>
#include <Adafruit_GFX.h>
#include "Adafruit_LEDBackpack.h"

Adafruit_AlphaNum4 alpha4 = Adafruit_AlphaNum4();

void setup() {
  alpha4.begin(0x70);  // เริ่มทำงานที่ address 0x70
}

void loop() {
  alpha4.writeDigitAscii(0, ' ');
  alpha4.writeDigitAscii(1, ' ');
  alpha4.writeDigitAscii(2, ' ');
  alpha4.writeDigitAscii(3, ' ');
  alpha4.writeDisplay();
  delay(300);
  alpha4.clear();

  alpha4.writeDigitAscii(0, ' ');
  alpha4.writeDigitAscii(1, ' ');
  alpha4.writeDigitAscii(2, ' ');
  alpha4.writeDigitAscii(3, '*');
  alpha4.writeDisplay();
  delay(300);
  alpha4.clear();

  alpha4.writeDigitAscii(0, ' ');
  alpha4.writeDigitAscii(1, ' ');
  alpha4.writeDigitAscii(2, '*');
  alpha4.writeDigitAscii(3, '*');
  alpha4.writeDisplay();
  delay(300);
  alpha4.clear();

  alpha4.writeDigitAscii(0, ' ');
  alpha4.writeDigitAscii(1, '*');
  alpha4.writeDigitAscii(2, '*');
  alpha4.writeDigitAscii(3, 'M');
  alpha4.writeDisplay();
  delay(300);
  alpha4.clear();

  alpha4.writeDigitAscii(0, '*');
  alpha4.writeDigitAscii(1, '*');
  alpha4.writeDigitAscii(2, 'M');
  alpha4.writeDigitAscii(3, 'Y');
  alpha4.writeDisplay();
  delay(300);
  alpha4.clear();

  alpha4.writeDigitAscii(0, '*');
  alpha4.writeDigitAscii(1, 'M');
  alpha4.writeDigitAscii(2, 'Y');
  alpha4.writeDigitAscii(3, ' ');
  alpha4.writeDisplay();
  delay(300);
  alpha4.clear();

  alpha4.writeDigitAscii(0, 'M');
  alpha4.writeDigitAscii(1, 'Y');
  alpha4.writeDigitAscii(2, ' ');
  alpha4.writeDigitAscii(3, 'A');
  alpha4.writeDisplay();
  delay(300);
  alpha4.clear();

  alpha4.writeDigitAscii(0, 'Y');
  alpha4.writeDigitAscii(1, ' ');
  alpha4.writeDigitAscii(2, 'A');
  alpha4.writeDigitAscii(3, 'R');
  alpha4.writeDisplay();
  delay(300);
  alpha4.clear();

  alpha4.writeDigitAscii(0, ' ');
  alpha4.writeDigitAscii(1, 'A');
  alpha4.writeDigitAscii(2, 'R');
  alpha4.writeDigitAscii(3, 'D');
  alpha4.writeDisplay();
  delay(300);
  alpha4.clear();

  alpha4.writeDigitAscii(0, 'A');
  alpha4.writeDigitAscii(1, 'R');
  alpha4.writeDigitAscii(2, 'D');
  alpha4.writeDigitAscii(3, 'U');
  alpha4.writeDisplay();
  delay(300);
  alpha4.clear();

  alpha4.writeDigitAscii(0, 'R');
  alpha4.writeDigitAscii(1, 'D');
  alpha4.writeDigitAscii(2, 'U');
  alpha4.writeDigitAscii(3, 'I');
  alpha4.writeDisplay();
  delay(300);
  alpha4.clear();

  alpha4.writeDigitAscii(0, 'D');
  alpha4.writeDigitAscii(1, 'U');
  alpha4.writeDigitAscii(2, 'I');
  alpha4.writeDigitAscii(3, 'N');
  alpha4.writeDisplay();
  delay(300);
  alpha4.clear();

  alpha4.writeDigitAscii(0, 'U');
  alpha4.writeDigitAscii(1, 'I');
  alpha4.writeDigitAscii(2, 'N');
  alpha4.writeDigitAscii(3, 'O');
  alpha4.writeDisplay();
  delay(300);
  alpha4.clear();

  alpha4.writeDigitAscii(0, 'I');
  alpha4.writeDigitAscii(1, 'N');
  alpha4.writeDigitAscii(2, 'O');
  alpha4.writeDigitAscii(3, '*');
  alpha4.writeDisplay(); // สั่งให้แสดงผล
  delay(300);
  alpha4.clear(); // ลบหน้าจอ

  alpha4.writeDigitAscii(0, 'N');
  alpha4.writeDigitAscii(1, 'O');
  alpha4.writeDigitAscii(2, '*');
  alpha4.writeDigitAscii(3, '*');
  alpha4.writeDisplay();
  delay(300);
  alpha4.clear();

  alpha4.writeDigitAscii(0, 'O');
  alpha4.writeDigitAscii(1, '*');
  alpha4.writeDigitAscii(2, '*');
  alpha4.writeDigitAscii(3, ' ');
  alpha4.writeDisplay();
  delay(300);
  alpha4.clear();

  alpha4.writeDigitAscii(0, '*');
  alpha4.writeDigitAscii(1, '*');
  alpha4.writeDigitAscii(2, ' ');
  alpha4.writeDigitAscii(3, ' ');
  alpha4.writeDisplay();
  delay(300);
  alpha4.clear();

  alpha4.writeDigitAscii(0, '*');
  alpha4.writeDigitAscii(1, ' ');
  alpha4.writeDigitAscii(2, ' ');
  alpha4.writeDigitAscii(3, ' ');
  alpha4.writeDisplay();
  delay(300);
  alpha4.clear();

  alpha4.writeDigitAscii(0, ' ');
  alpha4.writeDigitAscii(1, ' ');
  alpha4.writeDigitAscii(2, ' ');
  alpha4.writeDigitAscii(3, ' ');
  alpha4.writeDisplay();
  delay(1000);
  alpha4.clear();
}
