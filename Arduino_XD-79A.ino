int DO1 = 2;
int DO2 = 3;

void setup() {
  Serial.begin(9600);
  pinMode(DO1, INPUT);
  pinMode(DO2, OUTPUT);
}

void loop() {
  int s1 = digitalRead(DO1); // อ่านค่าเซนเซอร์จากตัวที่ 1
  int s2 = digitalRead(DO2); // อ่านค่าเซนเซอร์จากตัวที่ 2
  Serial.print(s1);
  Serial.print(" : ");
  Serial.println(s2);
  delay(500);
}
