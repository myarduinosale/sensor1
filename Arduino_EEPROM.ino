#include <EEPROM.h>
byte val0;
byte val1;


void setup() {
  Serial.begin(9600);
  EEPROM.write(0, 5);
  EEPROM.write(1, 10);
  val0 = EEPROM.read(0);
  val1 = EEPROM.read(1);
  Serial.println(val0);
  Serial.println(val1);


  
}

void loop() {

}
