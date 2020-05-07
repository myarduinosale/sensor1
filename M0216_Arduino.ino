int PE = 2; // ต่อกับ Pin PLAYE บนบอร์ดโมดูล
void setup() {
  pinMode(PE, OUTPUT);
  Serial.begin(9600);
}

void loop() {

  Serial.println("Play Sound");
  digitalWrite(PE, 1); // กดปุ่ม PLAYE
  delay(100);
  digitalWrite(PE, 0); // ปล่อยปุ่ม PLAYE
  delay(10000);
}
