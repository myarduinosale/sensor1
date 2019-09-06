const int CS = 10;
const int INC = 9;
const int UD = 8;

void setup() {
  pinMode(CS, OUTPUT);
  pinMode(INC, OUTPUT);
  pinMode(UD, OUTPUT);
  digitalWrite(CS, HIGH);
  digitalWrite(INC, HIGH);
  digitalWrite(UD, HIGH);
}

void loop() {
  for (int i = 0; i <= 100; i += 10) {
    setResistance(i); // กำหนดค่า % ความต้านทาน
    delay(1000);
  }
}

void setResistance(int percent) {
  digitalWrite(UD, LOW);
  digitalWrite(CS, LOW);
  for (int i = 0; i < 100; i++) {
    digitalWrite(INC, LOW);
    delayMicroseconds(1);
    digitalWrite(INC, HIGH);
    delayMicroseconds(1);
  }

  digitalWrite(UD, HIGH);
  for (int i = 0; i < percent; i++) {
    digitalWrite(INC, LOW);
    delayMicroseconds(1);
    digitalWrite(INC, HIGH);
    delayMicroseconds(1);
  }

  digitalWrite(CS, HIGH);
}
