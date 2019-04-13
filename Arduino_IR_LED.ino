#include <IRremote.h>
int RECV_PIN = 11;
int led1 = 2;
#define code1  16724175 // ค่าปุ่มกดที่ 1
#define code2  16718055 // ค่าปุ่มกดที่ 2
IRrecv irrecv(RECV_PIN);
decode_results results;
void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
  pinMode(led1, OUTPUT);
  digitalWrite(led1, LOW);
}
void loop() {
  if (irrecv.decode(&results)) {
    Serial.print("รหัสปุ่มกด: ");
    Serial.println(results.value);
    if (results.value == code1) { // ถ้าค่าที่ส่งมาตรงกับ ค่าในตัวแปร code1 ให้ทำใน ปีกกา if
      Serial.println("LED ON");
      digitalWrite(led1, HIGH);
    }
    if (results.value == code2) { // ถ้าค่าที่ส่งมาตรงกับ ค่าในตัวแปร code2 ให้ทำใน ปีกกา if
      Serial.println("LED OFF");
      digitalWrite(led1, LOW);
    }
    irrecv.resume(); // Receive the next value
  }
}
