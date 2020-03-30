int SensorPIR = 2;
int Relay = 3;
int val = 0;
int cou = 0;
void setup() {
  pinMode(SensorPIR, INPUT);  // sets the pin as output
  pinMode(Relay, OUTPUT);  // sets the pin as output
  Serial.begin(9600);
}
void loop() {
  val = digitalRead(SensorPIR);
  Serial.print("val = ");
  Serial.println(val);
  Serial.println(cou);
  if (val == 1) {
    if (cou < 200) { // จำนวนเคานท์สูงสุดสำหรับหน่วงเวลา relay สามารถปรับค่าได้
      cou = cou + 10; // จำนวนเคานท์ที่เพิ่มขึ้นเมื่อมีการเคลื่อนไหวหน้าเซ็นเซอร์ สามารถปรับค่าได้
    }
  }
  if (val == 0) {
    if (cou > 0) {
      cou = cou - 5; // จำนวนเคารท์ที่จะลดลงเมื่อไม่มีการเคลื่อนไหวหน้าเซ็นเซอร์ สามารถปรับค่าได้
    }
  }
  if (cou == 0) { //ดับ
    digitalWrite(Relay, HIGH);
    // Serial.println("Low");
  }
  if (cou > 0) { //ติด
    digitalWrite(Relay, LOW);
    // Serial.println("High");
  }
  delay(100);
}
