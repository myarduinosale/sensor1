int ledPin = 13;
int analogPin = A0;
int val = 0;
int buzz = 2;
void setup() {
pinMode(ledPin, OUTPUT);
pinMode(buzz, OUTPUT);
Serial.begin(9600);
}
 
void loop() {
val = analogRead(analogPin); //อ่านค่าสัญญาณ analog ขา A0
Serial.print("val = "); // พิมพ์ข้อความส่งเข้าคอมพิวเตอร์ "val = "
Serial.println(val); // พิมพ์ค่าของตัวแปร val
if (val > 500) {
digitalWrite(ledPin, HIGH); // สั่งให้ LED ติดสว่าง
digitalWrite(buzz, LOW); // สั่งให้ Buzzer ติด
}
else {
digitalWrite(ledPin, LOW); // สั่งให้ LED ดับ
digitalWrite(buzz, HIGH); // สั่งให้ Buzzer ดับ
}
delay(100);
}
