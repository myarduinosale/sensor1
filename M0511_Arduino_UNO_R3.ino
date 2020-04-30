int led1 = 13; // กำหนดขาใช้งาน
int Sensor = 2;
int val = 0;
void setup()
{
  pinMode(led1, OUTPUT);
  pinMode(Sensor, INPUT);
  digitalWrite(led1, LOW);
  Serial.begin(9600);
}
void loop()
{
  val = digitalRead(Sensor);
  Serial.print("val = "); // พิมพ์ข้อความส่งเข้าคอมพิวเตอร์ "val = "
  Serial.println(val); // พิมพ์ค่าของตัวแปร val
  if (val == HIGH) {
    digitalWrite(led1, HIGH); // ไฟ LED 1ติด
  }
  else {
    digitalWrite(led1, LOW); // ไฟ LED 1ดับ
  }
}
