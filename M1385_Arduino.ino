#include <SoftwareSerial.h>
#include <Wire.h>
#define RE 8
#define DE 7

const byte O2[] = {0x01, 0x03, 0x00, 0x06, 0x00, 0x01, 0x64, 0x0B};

byte values[11];
SoftwareSerial mod(2, 3);

void setup() {
  Serial.begin(9600);
  mod.begin(9600);
  pinMode(RE, OUTPUT);
  pinMode(DE, OUTPUT);
}

void loop() {
  float val1 ;
  val1 = Oxigen() * 0.1;
  Serial.print("O2: ");
  Serial.print(val1);
  Serial.println(" %");
  delay(2000);
}

byte Oxigen() {
  digitalWrite(DE, HIGH);
  digitalWrite(RE, HIGH);
  delay(10);
  if (mod.write(O2, sizeof(O2)) == 8) {
    digitalWrite(DE, LOW);
    digitalWrite(RE, LOW);
    for (byte i = 0; i < 7; i++) {
      //Serial.print(mod.read(),HEX);
      values[i] = mod.read();
      Serial.print(values[i], HEX);
    }
    Serial.println();
  }
  return values[4];
}
