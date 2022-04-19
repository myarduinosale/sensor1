#include <SoftwareSerial.h>
#include <Wire.h>
#define RE 8
#define DE 7

const byte O2[] = {0x01, 0x03, 0x00, 0x00, 0x00, 0x01, 0x84, 0x0A};

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
  Calculate();
  val1 = ((values[5]*256)+values[6]) * 0.1;
  val2 = ((values[3]*256)+values[4]) * 0.1;
  Serial.print("ระดับเสียง : ");
  Serial.print(val2);
  Serial.println(" dB");
  delay(2000);
}

byte Calculate() {
  digitalWrite(DE, HIGH);
  digitalWrite(RE, HIGH);
  delay(10);
  if (mod.write(O2, sizeof(O2)) == 8) {
    digitalWrite(DE, LOW);
    digitalWrite(RE, LOW);
    for (byte i = 0; i < 11; i++) {
      //Serial.print(mod.read(),HEX);
      values[i] = mod.read();
      //Serial.print(values[i], HEX);
      //Serial.print(" ");
    }
    Serial.println();
  }
  return values[6];
}
