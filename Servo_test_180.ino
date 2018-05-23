#include <Servo.h> // ส่งผนวกไฟล์ ชื่อ Servo.h เข้ามาใช้ในโปรแกรม 
int Servo1 = 9; // กําหนดให้ Servol แทน Pin Digital-9
Servo myservo; // สร้าง object ชื่อ myservo เพื่อควบคุม Servo
void setup()
{
  myservo.attach(Servo1); // กําหนดให้ใช้ขา Digital-9 สร้างสัญญาณควบคุม Servo
}
void loop()
{
  myservo.write(180); // กําหนดค่าตําแหน่งให้กับ Servo = 180 องศา

}

