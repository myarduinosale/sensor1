#include <ShiftRegister74HC595.h>
// create shift register object (number of shift registers, data pin, clock pin, latch pin)
ShiftRegister74HC595 sr (4, 2, 3, 4);
const int pot = A0;
int value, digit1, digit2, digit3, digit4;
uint8_t  numberB[] = {B00111111, //0
                      B00000110, //1
                      B01011011, //2
                      B01001111, //3
                      B01100110, //4
                      B01101101, //5
                      B01111101, //6
                      B00000111, //7
                      B01111111, //8
                      B01101111 //9
                     };
uint8_t  numberC[] = {B00000111, //หลักหน่วย
                      B00001011, //หลักสิบ
                      B00001101, //หลักร้อย
                      B00001110, //หลักพัน
                     };


void setup() {
  //blink();
}

void loop() {
  //ค่าที่ต้องการแสดง
  value = 1234;
  //Split number to digits:
  digit4 = value % 10 ;
  digit3 = (value / 10) % 10 ;
  digit2 = (value / 100) % 10 ;
  digit1 = (value / 1000) % 10 ;
  //Send them to 7 segment displays
  uint8_t numberToPrint[] = {numberC[0], numberB[digit4]};
  sr.setAll(numberToPrint);
  delay(1);
  uint8_t numberToPrint1[] = {numberC[1], numberB[digit3]};
  sr.setAll(numberToPrint1);
  delay(1);
  uint8_t numberToPrint2[] = {numberC[2], numberB[digit2]};
  sr.setAll(numberToPrint2);
  delay(1);
  uint8_t numberToPrint3[] = {numberC[3], numberB[digit1]};
  sr.setAll(numberToPrint3);

  delay(1);
}

//Blink
void blink() {
  for (int i = 0; i < 2; i++) {
    sr.setAllHigh(); // set all pins HIGH
    delay(1000);
    sr.setAllLow(); // set all pins LOW
    delay(1000);
  }
}
