int sensor = 2; // ตัวแปรของเครื่องรับเหรียญทำงานที่ขา 2
int i = 0;
int Twenty = 0; // ตัวแปรที่ใช้แทนมูลค่าธนบัตร ในที่นี้ใช้แทนธนบัตร 20 บาท สามารถเปลี่ยนได้
int Twenty_Bill = 0; // ตัวแปรที่ใช้แทนชนิดธนบัตร ในที่นี้ใช้แทนธนบัตร 20 บาท สามารถเปลี่ยนได้
int Fifty = 0; // ตัวแปรที่ใช้แทนมูลค่าธนบัตร ในที่นี้ใช้แทนธนบัตร 50 บาท สามารถเปลี่ยนได้
int Fifty_Bill = 0; // ตัวแปรที่ใช้แทนชนิดธนบัตร ในที่นี้ใช้แทนธนบัตร 50 บาท สามารถเปลี่ยนได้
int One_Hundred = 0; // ตัวแปรที่ใช้แทนมูลค่าธนบัตร ในที่นี้ใช้แทนธนบัตร 100 บาท สามารถเปลี่ยนได้
int One_Hundred_Bill = 0; // ตัวแปรที่ใช้แทนชนิดธนบัตร ในที่นี้ใช้แทนธนบัตร 100 บาท สามารถเปลี่ยนได้
int Five_Hundred = 0; // ตัวแปรที่ใช้แทนมูลค่าธนบัตร ในที่นี้ใช้แทนธนบัตร 500 บาท สามารถเปลี่ยนได้
int Five_Hundred_Bill = 0; // ตัวแปรที่ใช้แทนชนิดธนบัตร ในที่นี้ใช้แทนธนบัตร 500 บาท สามารถเปลี่ยนได้
int One_Thousand = 0; // ตัวแปรที่ใช้แทนมูลค่าธนบัตร ในที่นี้ใช้แทนธนบัตร 1000 บาท สามารถเปลี่ยนได้
int One_Thousand_Bill = 0; // ตัวแปรที่ใช้แทนชนิดธนบัตร ในที่นี้ใช้แทนธนบัตร 1000 บาท สามารถเปลี่ยนได้
int All = 0; // ตัวแปรสำหรับเก็บผลรวมจำนวนเงินทั้งหมด สามารถเปลี่ยนได้
int i20 = 0; // ตัวแปรสำหรับนับจำนวนธนบัตรแต่ละชนิด ในที่นี้ใช้แทนธนบัตร 20 บาท สามารถเปลี่ยนได้
int i50 = 0; // ตัวแปรสำหรับนับจำนวนธนบัตรแต่ละชนิด ในที่นี้ใช้แทนธนบัตร 50 บาท สามารถเปลี่ยนได้
int i100 = 0; // ตัวแปรสำหรับนับจำนวนธนบัตรแต่ละชนิด ในที่นี้ใช้แทนธนบัตร 100 บาท สามารถเปลี่ยนได้
int i500 = 0; // ตัวแปรสำหรับนับจำนวนธนบัตรแต่ละชนิด ในที่นี้ใช้แทนธนบัตร 500 บาท สามารถเปลี่ยนได้
int i1000 = 0; // ตัวแปรสำหรับนับจำนวนธนบัตรแต่ละชนิด ในที่นี้ใช้แทนธนบัตร 1000 บาท สามารถเปลี่ยนได้
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
    if (count >= 2 && count <5) {
      i20 = i20 + 1;
      Twenty = i20 * 20; // มูลค่าธนบัตร
      Twenty_Bill = 20; // ขนิดธนบัตร
      Serial.print("ชนิดธนบัตรล่าสุด: ");
      Serial.print(Twenty_Bill); Serial.println(" บาท");
      Serial.println();
    }
    if (count >=5 && count <=9) {
      i50 = i50 + 1;
      Fifty = i50 * 50;
      Fifty_Bill = 50;
      Serial.print("ชนิดธนบัตรล่าสุด: ");
      Serial.print(Fifty_Bill); Serial.println(" บาท");
      Serial.println();
    }
  
    if (count >= 10 && count <= 30) {
      i100 = i100 + 1;
      One_Hundred = i100 * 100;
      One_Hundred_Bill = 100;
      Serial.print("ชนิดธนบัตรล่าสุด: ");
      Serial.print(One_Hundred_Bill); Serial.println(" บาท");
      Serial.println();
    }
    if (count >= 31 && count <= 90) {
      i500 = i500 + 1;
      Five_Hundred = i500 * 500;
      Five_Hundred_Bill = 500;
      Serial.print("ชนิดธนบัตรล่าสุด: ");
      Serial.print(Five_Hundred_Bill); Serial.println(" บาท");
      Serial.println();
    }
    if (count > 100) {
      i1000 = i1000 + 1;
      One_Thousand = i1000 * 1000;
      One_Thousand_Bill = 1000;
      Serial.print("ชนิดธนบัตรล่าสุด: ");
      Serial.print(One_Thousand_Bill); Serial.println(" บาท");
      Serial.println();
    }
    Serial.print(" รวมชนิดธนบัตร 20 บาท: ");
    Serial.print(i20); Serial.println(" ใบ");
    Serial.print(" รวมชนิดธนบัตร 50 บาท: ");
    Serial.print(i50); Serial.println(" ใบ");
    Serial.print(" รวมชนิดธนบัตร 100 บาท: ");
    Serial.print(i100); Serial.println(" ใบ");
    Serial.print(" รวมชนิดธนบัตร 500 บาท: ");
    Serial.print(i500); Serial.println(" ใบ");
    Serial.print(" รวมชนิดธนบัตร 1000 บาท: ");
    Serial.print(i1000); Serial.println(" ใบ");
    Serial.println();
    All = Twenty + Fifty + One_Hundred + Five_Hundred + One_Thousand;
    Serial.print(" ยอดเงินรวมทั้งหมด: ");
    Serial.print(All); Serial.println(" บาท");
    Serial.println("--------------------------------");
    Serial.println();
    count = 0;
  }
}


void doCounter() {
  isCounter = true;
  count++;
}
