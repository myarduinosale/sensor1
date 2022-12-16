#include <SoftwareSerial.h>
#include <Wire.h>
#define RE 8
#define DE 7
 
const byte DB[] = {0x01 ,0x03 ,0x00 ,0x00 ,0x00 ,0x02 ,0xC4 ,0x0B};
 
byte values[20];
SoftwareSerial mod(2, 3);
 
void setup() {
Serial.begin(9600);
mod.begin(9600);
pinMode(RE, OUTPUT);
pinMode(DE, OUTPUT);
}
 
void loop() {
float val1 ;
float val2 ;
val1 = ((values[5]*256)+Decibel()) * 0.1;
val2 = ((values[3]*256)+values[4]) * 0.1;
Serial.print("ระดับเสียง: ");
Serial.print(val2);
Serial.println(" dB ");
delay(2000);
}
 
byte Decibel() {
digitalWrite(DE, HIGH);
digitalWrite(RE, HIGH);
delay(10);
if (mod.write(DB, sizeof(DB)) == 8) {
digitalWrite(DE, LOW);
digitalWrite(RE, LOW);
for (byte i = 0; i < 11; i++) {
//Serial.print(mod.read(),HEX);
values[i] = mod.read();
//Serial.print(values[i], HEX);
Serial.print(" ");
}
Serial.println();
}
return values[6];
}
