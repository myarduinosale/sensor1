#include "LedControl.h"
 
// Arduino Pin 7 to DIN, 6 to Clk, 5 to LOAD, no.of devices is 1
/*
Arduino -> Module MAX7219
ขา7 -> DIN
ขา6 -> CLK
ขา5 -> DIN
5V -> Vcc
Gnd -> Gnd
*/
LedControl lc=LedControl(7,6,5,1); // เลข 1 คือจำนวนโมดูลแสดงผลที่ต่อ ในที่นี้ต่อ 1 โมดูล
void setup()
{
// กำหนดค่าเริ่มต้น MAX7219 device
lc.shutdown(0,false); // Enable display
lc.setIntensity(0,15); // ปรับระดับความสว่างได้ 16 ระดับ 0 คือค่าต่ำสุด 15 คือค่าสูงสุด
lc.clearDisplay(0); // Clear display register
}
void loop()
{
lc.setChar(0,0,'C',false);
lc.setChar(0,1,'A',false);
lc.setChar(0,2,'-',false);
lc.setChar(0,3,'5',false);
lc.setChar(0,4,'4',false);
lc.setChar(0,5,'3',false);
lc.setChar(0,6,'2',false);
lc.setChar(0,7,'1',false);
 
delay(1000);
}
