#include <TM1637.h>
#define CLK 6 
#define DIO 7 
TM1637 Display1(CLK, DIO);

#define CHAR_BLANK 127
void setup() {
  Display1.init();
  Display1.set(BRIGHT_DARKEST); // กำหนดความสว่าง 0-7 หรือกำหนดผ่านค่าคง
}          // BRIGHT_TYPICAL = 2 , BRIGHT_DARKEST = 0 , BRIGHTEST = 7

void loop() {
  Display1.display(0, 1); // แสดงเลข 1 ที่หลัก 0
  delay(1000);            // *** หลัก (0,1,2,3) นับจากซ้ายตามลำดับ

  Display1.display(1, 2); // แสดงเลข 2 ที่หลัก 1
  delay(1000);

  Display1.display(2, 5); // แสดงเลข 5 ที่หลัก 2
  delay(1000);

  Display1.display(3, 8); // แสดงเลข 8 ที่หลัก 3
  delay(1000);

  Display1.display(0, CHAR_BLANK); // แสดง ' ' (ช่องว่าง) ที่หลัก 0
  delay(1000);

  Display1.display(1, CHAR_BLANK); // แสดง ' ' (ช่องว่าง) ที่หลัก 1
  delay(1000);

  Display1.display(2, CHAR_BLANK); // แสดง ' '  (ช่องว่าง)ที่หลัก 2
  delay(1000);

  Display1.display(3, CHAR_BLANK); // แสดง ' ' (ช่องว่าง) ที่หลัก 3
  delay(1000);

  Display1.point(POINT_ON); // เปิดแสดงจุด ":" ระหว่างหลัก 1 กับ หลัก 2
  Display1.clearDisplay();  // ต้องตาม Function นี้  จุดถึงจะแสดง
  delay(1000);

  Display1.point(POINT_OFF);  // ปิดแสดงจุด ":" ระหว่างหลัก 1 กับ หลัก 2
  Display1.clearDisplay();  // ต้องตาม Function นี้  จุดถึงจะปิดไม่แสดง
  delay(1000);

  Display1.point(POINT_ON);
  Display1.clearDisplay();
  Display1.display(0, 1);
  Display1.display(1, 2);
  Display1.display(2, 3);
  Display1.display(3, 4);
  delay(1000);

  Display1.display(0, 2);
  Display1.display(1, 3);
  Display1.display(2, 4);
  Display1.display(3, 5);
  delay(1000);

  Display1.display(0, 3);
  Display1.display(1, 4);
  Display1.display(2, 5);
  Display1.display(3, 6);
  delay(1000);

  Display1.display(0, 4);
  Display1.display(1, 5);
  Display1.display(2, 6);
  Display1.display(3, 7);
  delay(1000);

  Display1.display(0, 5);
  Display1.display(1, 6);
  Display1.display(2, 7);
  Display1.display(3, 8);
  delay(1000);

  Display1.display(0, 6);
  Display1.display(1, 7);
  Display1.display(2, 8);
  Display1.display(3, 9);
  delay(1000);

  Display1.display(0, 7);
  Display1.display(1, 8);
  Display1.display(2, 9);
  Display1.display(3, 0);
  delay(1000);
  Display1.clearDisplay();

  Display1.display(0, 8);
  Display1.display(1, 9);
  Display1.display(2, 0);
  delay(1000);
  Display1.clearDisplay();

  Display1.display(0, 9);
  Display1.display(1, 0);
  delay(1000);
  Display1.clearDisplay();

  Display1.display(0, 0);
  delay(1000);
  Display1.clearDisplay();

  Display1.display(0, 8);
  Display1.display(1, 8);
  Display1.display(2, 8);
  Display1.display(3, 8);
  delay(1000);

  Display1.point(POINT_OFF);
  Display1.clearDisplay();
  delay(1000);
 
}
