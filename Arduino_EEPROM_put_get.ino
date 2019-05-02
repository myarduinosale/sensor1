#include <EEPROM.h>
float val0;
float x = 124.56;
char val1[18] ;
char data[] = "www.myarduino.net";

void setup() {
  Serial.begin(9600);

  EEPROM.put(0, x);
  EEPROM.put(sizeof(x), data);

  EEPROM.get(0, val0);
  EEPROM.get(sizeof(x), val1);
  Serial.println(val0);
  Serial.println(val1);



}

void loop() {

}
