#include <Wire.h>
#include <Adafruit_GFX.h>
#include "Adafruit_LEDBackpack.h"

Adafruit_7segment matrix = Adafruit_7segment();

void setup() {
  matrix.begin(0x70);
}

void loop() {

  // แสดงแบบตัวเลขจำนวนเต็ม
  matrix.print(1234, DEC);
  matrix.writeDisplay();
  delay(1000);

  // แสดงแบบตัวเลขทศนิยม
  matrix.print(56.78);
  matrix.writeDisplay();
  delay(1000);

  // แสดงทีละหลัก แสดงจุดทศนิยม และ วาดจุด :
  matrix.writeDigitNum(0, 9, true); // true คือการเพิ่มจุดทศนิยมที่หลังตัวเลข
  matrix.writeDigitNum(1, 0, false); // false คือไม่ต้องใส่จุดทศนิยมที่หลังตัวเลข
  matrix.drawColon(true); // สำหรับเพิ่มจุดโคลอน ถ้าไม่ต้องการสามารถลบออกได้
  matrix.writeDigitNum(3, 1, true);
  matrix.writeDigitNum(4, 2, false);
  matrix.writeDisplay();
  delay(1000);
  matrix.clear();

  // แสดงตัวเลขเลื่อน
  matrix.writeDigitNum(4, 1, false);
  matrix.writeDisplay();
  delay(300);

  matrix.writeDigitNum(3, 1, false);
  matrix.writeDigitNum(4, 2, false);
  matrix.writeDisplay();
  delay(300);

  matrix.writeDigitNum(1, 1, false);
  matrix.writeDigitNum(3, 2, false);
  matrix.writeDigitNum(4, 3, false);
  matrix.writeDisplay();
  delay(300);

  matrix.writeDigitNum(0, 1, false);
  matrix.writeDigitNum(1, 2, false);
  matrix.writeDigitNum(3, 3, false);
  matrix.writeDigitNum(4, 4, false);
  matrix.writeDisplay();
  delay(300);

  matrix.writeDigitNum(0, 2, false);
  matrix.writeDigitNum(1, 3, false);
  matrix.writeDigitNum(3, 4, false);
  matrix.writeDigitNum(4, 5, false);
  matrix.writeDisplay();
  delay(300);

  matrix.writeDigitNum(0, 3, false);
  matrix.writeDigitNum(1, 4, false);
  matrix.writeDigitNum(3, 5, false);
  matrix.writeDigitNum(4, 6, false);
  matrix.writeDisplay();
  delay(300);

  matrix.writeDigitNum(0, 4, false);
  matrix.writeDigitNum(1, 5, false);
  matrix.writeDigitNum(3, 6, false);
  matrix.writeDigitNum(4, 7, false);
  matrix.writeDisplay();
  delay(300);

  matrix.writeDigitNum(0, 5, false);
  matrix.writeDigitNum(1, 6, false);
  matrix.writeDigitNum(3, 7, false);
  matrix.writeDigitNum(4, 8, false);
  matrix.writeDisplay();
  delay(300);

  matrix.writeDigitNum(0, 6, false);
  matrix.writeDigitNum(1, 7, false);
  matrix.writeDigitNum(3, 8, false);
  matrix.writeDigitNum(4, 9, false);
  matrix.writeDisplay();
  delay(300);

  matrix.writeDigitNum(0, 7, false);
  matrix.writeDigitNum(1, 8, false);
  matrix.writeDigitNum(3, 9, false);
  matrix.writeDigitNum(4, 0, false);
  matrix.writeDisplay();
  delay(300);
  matrix.clear();

  matrix.writeDigitNum(0, 8, false);
  matrix.writeDigitNum(1, 9, false);
  matrix.writeDigitNum(3, 0, false);
  matrix.writeDisplay();
  delay(300);
  matrix.clear();

  matrix.writeDigitNum(0, 9, false);
  matrix.writeDigitNum(1, 0, false);
  matrix.writeDisplay();
  delay(300);
  matrix.clear();

  matrix.writeDigitNum(0, 0, false);
  matrix.writeDisplay();
  delay(300);
  matrix.clear();

  matrix.writeDisplay();
  delay(2000);
}
