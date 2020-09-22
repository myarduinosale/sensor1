int sensor = 2;
int led = 3;
int i = 0;
int c = 0;
void setup() {
  pinMode(sensor, INPUT);
  pinMode(led, OUTPUT);
  attachInterrupt(0, doCounter, FALLING); // ทำงานแบบ interrupt เบอร์ 0 ในนี้คือขา 2
  // เมื่อเกิดเหตุการณ์ แรงดันที่ขา 2 มีการเปลี่ยนแปลงจากสัญญาณสูงเป็นต่ำ ให้ทำในฟังก์ชั่น doCounter
  Serial.begin(9600);
}
boolean isCounter = false;
int count = 0;
void loop() {
  if (isCounter == true) {
    isCounter = false;
    //Serial.println(count);
    if (count > 1) {
      i = i + 1;
      Serial.print("จำนวนเหรียญ : ");
      Serial.println(i);
      c = i * 10;
      Serial.print("จำนวนเงิน : ");
      Serial.print(c);
      Serial.println(" บาท");
      delay(1000);
      count = 0;
    }
    if (c == 30) {
      c = c - 30;
      i = i - 3;
      digitalWrite (led, HIGH);
      Serial.println();
      Serial.print("ระบบทำงาน");
      Serial.println();
      Serial.print("LED ON");
      Serial.println();
      Serial.println();
      delay(10000);
      Serial.print("เคลียร์เหรียญ / จำนวนเงิน");
      Serial.println();
      Serial.print("จำนวนเหรียญ : ");
      Serial.println(i);
      Serial.print("จำนวนเงิน : ");
      Serial.print(c);
      Serial.println(" บาท");
      Serial.println();
      Serial.print("หยุดการทำงานของระบบ");
      Serial.println();
      digitalWrite (led, LOW);
      Serial.print("LED OFF");
      Serial.println();
      Serial.println();
    }
  }
}

void doCounter() { // เมื่อเซ็นเซอร์ตรวจจับวัตถุ
  isCounter = true;
  count++;
  delay(1000);
}
