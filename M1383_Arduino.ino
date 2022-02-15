#include <SoftwareSerial.h>
#include <Wire.h>
#define RE 8
#define DE 7

const byte O2[] = {0x01 ,0x03 ,0x00 ,0x00 ,0x00 ,0x03 ,0x05 ,0xCB};

byte values[20];
SoftwareSerial mod(2, 3);

void setup() {
  Serial.begin(4800);
  mod.begin(4800);
  pinMode(RE, OUTPUT);
  pinMode(DE, OUTPUT);
}

void loop() {
  float val1 ;
  float val2 ;
  float val3 ;
  val1 = ((values[5]*256)+Oxigen()) * 0.1;
  Serial.print("อุณหภูมิ: ");
  Serial.print(val1);
  Serial.print(" C   ");
  val2 = ((values[3]*256)+values[4]) * 0.1;
  Serial.print("ความชื้น: ");
  Serial.print(val2);
  Serial.print(" %   ");
  val3 = ((values[7]*256)+values[8]) * 0.1;
  Serial.print("EC: ");
  Serial.print(val3);
  Serial.println(" us/cm");
  delay(2000);
}

byte Oxigen() {
  digitalWrite(DE, HIGH);
  digitalWrite(RE, HIGH);
  delay(10);
  if (mod.write(O2, sizeof(O2)) == 8) {
    digitalWrite(DE, LOW);
    digitalWrite(RE, LOW);
    for (byte i = 0; i < 11; i++) {
      //Serial.print(mod.read(),HEX);
      values[i] = mod.read();
      Serial.print(values[i], HEX);
      Serial.print(" ");
    }
    Serial.println();
  }
  return values[6];
}
