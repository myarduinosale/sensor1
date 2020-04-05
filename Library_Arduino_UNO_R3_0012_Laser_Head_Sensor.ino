int sw = 6; // ประกาศตัวแปรให้สวิตซ์อยู่ที่ ขาที่ 6
int val = 0;
int Laser = 2; // ประกาศตัวแปรให้เลเซอร์อยู่ที่ ขาที่ 2
int I = 0;
void setup() {
  pinMode(Laser, OUTPUT);
  Serial.begin(9600);
}
void loop() {
  val = digitalRead(sw);
  //Serial.println(val);
  if (I != val) {
    I = val;
    if (val == 1) {
      digitalWrite(Laser, HIGH); // ถ้าค่า val เท่ากับ 1 สั่งให้ Laser ติด
      Serial.println("Laser_ON");
    }
    if (val == 0) {
      digitalWrite(Laser, LOW); // ถ้าค่า val ไม่ใช่ 1 สั่งให้ Laser ดับ
      Serial.println("Laser_OFF");
    }
  }
}
