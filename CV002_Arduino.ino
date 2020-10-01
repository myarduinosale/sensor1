int sensor = 2; // ตัวแปรของเครื่องรับเหรียญทำงานที่ขา 2
int i = 0;
int k = 0; // ตัวแปรที่ใช้แทนมูลค่าเหรียญ ในที่นี้ใช้แทนเหรียญ 10 บาท สามารถเปลี่ยนได้
int kc = 0; // ตัวแปรที่ใช้แทนขนิดเหรียญ ในที่นี้ใช้แทนเหรียญ 10 บาท สามารถเปลี่ยนได้
int s = 0; // ตัวแปรที่ใช้แทนมูลค่าเหรียญ ในที่นี้ใช้แทนเหรียญ 1 บาท สามารถเปลี่ยนได้
int sc = 0; // ตัวแปรที่ใช้แทนขนิดเหรียญ ในที่นี้ใช้แทนเหรียญ 1 บาท สามารถเปลี่ยนได้
int j = 0; // ตัวแปรที่ใช้แทนมูลค่าเหรียญ ในที่นี้ใช้แทนเหรียญ 5 บาท สามารถเปลี่ยนได้
int jc = 0; // ตัวแปรที่ใช้แทนขนิดเหรียญ ในที่นี้ใช้แทนเหรียญ 5 บาท สามารถเปลี่ยนได้
int a = 0; // ตัวแปรสำหรับเก็บผลรวมจำนวนเงินทั้งหมด สามารถเปลี่ยนได้
int i10 = 0; // ตัวแปรสำหรับนับจำนวนเหรียญแต่ละชนิด ในที่นี้ใช้แทนเหรียญ 10 บาท สามารถเปลี่ยนได้
int i5 = 0; // ตัวแปรสำหรับนับจำนวนเหรียญแต่ละชนิด ในที่นี้ใช้แทนเหรียญ 5 บาท สามารถเปลี่ยนได้
int i1 = 0; // ตัวแปรสำหรับนับจำนวนเหรียญแต่ละชนิด ในที่นี้ใช้แทนเหรียญ 1 บาท สามารถเปลี่ยนได้
void setup() {
  pinMode(sensor, INPUT);
  attachInterrupt(0, doCounter, FALLING);
  Serial.begin(9600);
}
boolean isCounter = false;
int count = 0;
void loop() {
  if (isCounter == true) {
    isCounter = false;
    //Serial.println(count);
    delay(500);
  }
  if (i != 1000 && count != 0 ) {
    i = i + 1;
  }
  if (i == 1000) {
    i = 0;
    if (count == 10) {
      i10 = i10 + 1;
      k = i10 * 10; // มูลค่าเหรียญ
      kc = 10; // ขนิดเหรียญ
      Serial.print("ชนิดเหรียญล่าสุด: ");
      Serial.print(kc);Serial.println(" บาท");
      Serial.println();
    }
    if (count == 5) {
      i5 = i5 + 1;
      j = i5 * 5;
      jc = 5;
      Serial.print("ชนิดเหรียญล่าสุด: ");
      Serial.print(jc);Serial.println(" บาท");
      Serial.println();
    }
    if (count == 1) {
      i1 = i1 + 1;
      s = i1 * 1;
      sc = 1;
      Serial.print("ชนิดเหรียญล่าสุด: ");
      Serial.print(sc);Serial.println(" บาท");
      Serial.println();
    }
    Serial.print("   รวมชนิดเหรียญ 10 บาท: ");
    Serial.print(i10);Serial.println(" เหรียญ");
    Serial.print("   รวมชนิดเหรียญ  5 บาท: ");
    Serial.print(i5);Serial.println(" เหรียญ");
    Serial.print("   รวมชนิดเหรียญ  1 บาท: ");
    Serial.print(i1);Serial.println(" เหรียญ");
    Serial.println();
    a = s + k + j;
    Serial.print("         ยอดเงินรวมทั้งหมด: ");
    Serial.print(a);Serial.println(" บาท");
    Serial.println();
    count  = 0;
  }
}


void doCounter() {
  isCounter = true;
  count++;
}
