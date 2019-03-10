void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.println("Test for myarduino"); // พิมพ์ข้อมความส่งเข้าคอมพิวเตอร์ "Test for myarduino"
  for (int x = 0; x < 10; x++) { //ให้วนรอบโดยกำหนดให้ X = 0 ถึง 9
    Serial.print("X = "); // พิมพ์ข้อมความส่งเข้าคอมพิวเตอร์ "X = "
    Serial.println(x); // พิมพ์ค่าชองตัวแปร x
    delay(200); //หน่วงเวลา 200mS
  }
}
