int LED_R = 2; // ตัวแปรแทนหลอดไฟ LED สีแดง = ขา 2
int LED_G = 3; // ตัวแปรแทนหลอดไฟ LED สีเขียว = ขา 3
int buzzer = 4; // ตัวแปรแทนลำโพง = ขา 4
int val = 0; // ตัวแปรเก็บค่าสถานะ
#if 0
#include <SPI.h>
#include <PN532_SPI.h>
#include "PN532.h"

PN532_SPI pn532spi(SPI, 10);
PN532 nfc(pn532spi);

/* When the number after #elif set as 1, it will be switch to HSU Mode*/
#elif 0
#include <PN532_HSU.h>
#include <PN532.h>

PN532_HSU pn532hsu(Serial1);
PN532 nfc(pn532hsu);

/* When the number after #if & #elif set as 0, it will be switch to I2C Mode*/
#else
#include <Wire.h>
#include <PN532_I2C.h>
#include <PN532.h>
#include <NfcAdapter.h>

PN532_I2C pn532i2c(Wire);
PN532 nfc(pn532i2c);
#endif

void setup(void) {
  pinMode(LED_R, OUTPUT); // กำหนดสถานะหลอดไฟเป็นกระแสออก
  pinMode(LED_G, OUTPUT); // กำหนดสถานะหลอดไฟเป็นกระแสออก
  pinMode(buzzer, OUTPUT); // กำหนดสถานะลำโพงเป็นกระแสออก
  digitalWrite(buzzer, HIGH); // กำหนดสถานะเริ่มต้นของลำโพงเป็นปิด (buzzer รุ่นนี้สถานะ HIGH คือปิดการใช้งานลำโพง)
  Serial.begin(115200);
  Serial.println("Hello!");

  nfc.begin();

  uint32_t versiondata = nfc.getFirmwareVersion();
  if (! versiondata) {
    Serial.print("Didn't find PN53x board");
    while (1); // halt
  }

  // Got ok data, print it out!
  Serial.print("Found chip PN5"); Serial.println((versiondata >> 24) & 0xFF, HEX);
  Serial.print("Firmware ver. "); Serial.print((versiondata >> 16) & 0xFF, DEC);
  Serial.print('.'); Serial.println((versiondata >> 8) & 0xFF, DEC);

  // Set the max number of retry attempts to read from a card
  // This prevents us from waiting forever for a card, which is
  // the default behaviour of the PN532.
  nfc.setPassiveActivationRetries(0xFF);

  // configure board to read RFID tags
  nfc.SAMConfig();

  Serial.println("Waiting for an ISO14443A card");
}

void loop(void) {
  boolean success;
  uint8_t uid[] = { 0, 0, 0, 0, 0, 0, 0 };  // Buffer to store the returned UID
  uint8_t uidLength;                        // Length of the UID (4 or 7 bytes depending on ISO14443A card type)

  // Wait for an ISO14443A type cards (Mifare, etc.).  When one is found
  // 'uid' will be populated with the UID, and uidLength will indicate
  // if the uid is 4 bytes (Mifare Classic) or 7 bytes (Mifare Ultralight)
  success = nfc.readPassiveTargetID(PN532_MIFARE_ISO14443A, &uid[0], &uidLength);

  if (success) {
    Serial.println("Found a card!");
    Serial.print("UID Length: "); Serial.print(uidLength, DEC); Serial.println(" bytes");
    Serial.print("UID Value: ");
    for (uint8_t i = 0; i < uidLength; i++)
    {
      Serial.print(" -"); Serial.print(uid[i], DEC);
    }
    Serial.println("");
    // Wait 1 second before continuing
    delay(1000);
  }
  else
  {
    // PN532 probably timed out waiting for a card
    Serial.println("Timed out waiting for a card");
  }
  
  if (uid[0] == 128 || uid[1] == 49 || uid[2] == 2 || uid[3] == 50 )
  // *** uid คือข้อมูลเลขฐานของการ์ดหรือแท็ก ซึ่งการ์ดและแท็กแต่ละชิ้นก็จะมี uid ที่แตกต่างกัน ***
  // *** ผู้ใช้งานสามารถหา uid แต่ละตำแหน่งได้จากการใช้โมดูล PN532 อ่านข้อมูลของการ์ดหรือแท็ก ***
  {
    val = val + 1; { //กำหนดค่า val ให้เพิ่มขึ้นตามที่กำหนดไว้ เมื่อมีการ์ดหรือแท๊กที่มีชุดข้อมูลตรงกับ uid ด้านบนเข้าในระยะสแกน
      if (val == 1) { // กำหนดการใช้งาน เมื่อค่า val = 1 แล้ว...(คำสั่งอยู่ข้างล่าง)...
        digitalWrite(buzzer, LOW); // สั่งเปิดใช้งานลำโพง (buzzer รุ่นนี้สถานะ LOW คือการเปิดการใช้งานลำโพง)
        delay(100); // ระยะเวลาก่อนจะดำเนินการทำคำสั่งต่อไป 100 = 0.1 วินาที
        digitalWrite(buzzer, HIGH); // สั่งปิดใช้งานลำโพง (buzzer รุ่นนี้สถานะ HIGH คือการปิดการใช้งานลำโพง)
        digitalWrite(LED_R, HIGH); // สั่งเปิดใช้งานหลอดไฟ LED (HIGH = เปิด)
        Serial.println("LED Red ON"); // สั่งให้โปรแกรมแสดงข้อความออกมาผ่านหน้าจอ Serial Monitor เมื่อทำคำสั่งเสร็จ
      }
      if (val == 2) {
        digitalWrite(buzzer, LOW);
        delay(100);
        digitalWrite(buzzer, HIGH);
        digitalWrite(LED_R, LOW); // สั่งปิดหลอดไฟ LED (LOW = ปิด)
        Serial.println("LED Red OFF");
        val = 0;
      }
    }
  }
  if (uid[0] == 105 || uid[1] == 89 || uid[2] == 25 || uid[3] == 201 ) {
    val = val + 3; {
      if (val == 3) {
        digitalWrite(buzzer, LOW);
        delay(100);
        digitalWrite(buzzer, HIGH);
        digitalWrite(LED_G, HIGH);
        Serial.println("LED Green ON");
      }
      if (val == 6) {
        digitalWrite(buzzer, LOW);
        delay(100);
        digitalWrite(buzzer, HIGH);
        digitalWrite(LED_G, LOW);
        Serial.println("LED Green OFF");
        val = 0;
      }
    }
  }
  if (val >= 7) {
    digitalWrite(buzzer, LOW);
    delay(100);
    digitalWrite(buzzer, HIGH);
    delay(100);
    digitalWrite(buzzer, LOW);
    delay(100);
    digitalWrite(buzzer, HIGH);
    delay(100);
    digitalWrite(buzzer, LOW);
    delay(100);
    digitalWrite(buzzer, HIGH);
    digitalWrite(LED_R, LOW);
    digitalWrite(LED_G, LOW);
    Serial.println("All LED OFF");
    val = 0;
  }
}
