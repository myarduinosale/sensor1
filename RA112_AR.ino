#include <Servo.h>
Servo myservo; //ประกาศตัวแปรแทน Servo

void setup()
{
  myservo.attach(9); // กำหนดขา 9 ควบคุม Servo
}
void loop()
{
  myservo.writeMicroseconds(500); // ค่า PWM ที่สั่งให้ Servo หมุนตามเข็มนาฬิกาด้วยความเร็วสูงสุด
  delay(3000); // หน่วงเวลา 3000ms servo จะหมุนไปเรื่อยๆจนกว่าจะครบเวลาที่ delay ไว้
  myservo.writeMicroseconds(1500); // สั่งให้ Servo หยุด
  delay(3000); // หน่วงเวลา 3000ms servo จะหยุดหมุนจนกว่าจะครบเวลาที่ delay ไว้
  myservo.writeMicroseconds(2500); // ค่า PWM ที่สั่งให้ Servo หมุนทวนเข็มนาฬิกาด้วยความเร็วสูงสุด
  delay(3000); // หน่วงเวลา 3000ms servo จะหมุนไปเรื่อยๆจนกว่าจะครบเวลาที่ delay ไว้
}

//*** ยิ่งค่า PWM ใกล้ 1500 มากเท่าไหร่อัตราการหมุนของ Servo ก็จะยิ่งช้าลง ***//
