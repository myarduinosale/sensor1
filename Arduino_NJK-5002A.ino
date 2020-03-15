  สายสีน้ำตาล VCC - 5V
  สายสีน้ำเงิน GND - GND
  สายสีดำ OUT - A0
*/

void setup() {
  pinMode(A0, INPUT);
  Serial.begin(9600);
}

void loop() {
  int val = digitalRead(A0);
  if (val == 1) {
    Serial.println("Detected");
  }
  delay(500);
}
