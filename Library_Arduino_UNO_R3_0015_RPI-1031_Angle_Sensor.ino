int analogPin = 5; //ประกาศตัวแปร ให้ analogPin แทนขา analog ขาที่5
int analogPin4 = 4;
int val = 0;
int va2 = 0;
void setup() {
  Serial.begin(9600);
}

void loop() {
  val = analogRead(analogPin);  //อ่านค่าสัญญาณ analog ขา5 ที่ต่อกับ RPI-1031
  va2 = analogRead(analogPin4);  //อ่านค่าสัญญาณ analog ขา4 ที่ต่อกับ RPI-1031

  if (val == 0 && va2 > 0 ) {
    Serial.println("Front");
  }
  if (va2 == 0 && val > 0 ) {
    Serial.println("Back");
  }
  if (va2 == 0 && val == 0 ) {
    Serial.println("Right");
  }
  if (va2 > 0 && val > 0 ) {
    Serial.println("Left");
  }
  delay(500);
}
