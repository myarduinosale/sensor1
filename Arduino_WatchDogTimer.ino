#include <avr/wdt.h>
void setup()
{
  Serial.begin(9600);
  wdt_enable(WDTO_2S); 
  //ตั้งค่าถ้า โปรแกรมใน void loop ทำงาน เกิน 2 วินาที 
  //ให้ Reset โปรแกรมใหม่
  Serial.println("Arduino Reset");
}
void loop()
{
  //wdt_disable();
  Serial.println("Arduino working");
  delay(3000);// หน่วงเวลา 3000ms
  wdt_reset(); //Reset การจับเวลาใหม่
}
