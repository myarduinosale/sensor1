int sw = 6; // ประกาศตัวแปรให้สวิตซ์อยู่ที่ ขาที่ 6
int val = 0;
int ledPin = 7; // ประกาศตัวแปรให้ LED อยู่ที่ ขาที่ 7
int I = 0;
void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}
void loop() {
  val = digitalRead(sw);
  //Serial.println(val);
  if (I != val) {
    I = val;
    if (val == 1) {
      digitalWrite(ledPin, HIGH); // ถ้าค่า val เท่ากับ 1 สั่งให้ LED ติด
      Serial.println("1");
    }
    if (val == 0) {
      digitalWrite(ledPin, LOW); // ถ้าค่า val ไม่ใช่ 1 สั่งให้ LED ดับ
      Serial.println("0");
    }
  }
}
