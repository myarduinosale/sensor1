int r1 = 7; // ควบคุม Relay ตัวที่ 1 ต่อขา7
int r2 = 6; // ควบคุม Relay ตัวที่ 2 ต่อขา6
int r3 = 5; // ควบคุม Relay ตัวที่ 3 ต่อขา5
int r4 = 4; // ควบคุม Relay ตัวที่ 4 ต่อขา4

void setup() {
  pinMode(r1, OUTPUT);
  pinMode(r2, OUTPUT);
  pinMode(r3, OUTPUT);
  pinMode(r4, OUTPUT);
  digitalWrite(r1,0);
  digitalWrite(r2,0);
  digitalWrite(r3,0);
  digitalWrite(r4,0);
  Serial.begin(9600);

}

void loop() {
  Serial.println("Test Relay 1");
  digitalWrite(r1,1);
  delay(1000);
  digitalWrite(r1,0);
  delay(1000);
  Serial.println("Test Relay 2");
  digitalWrite(r2,1);
  delay(1000);
  digitalWrite(r2,0);
  delay(1000);
  Serial.println("Test Relay 3");
  digitalWrite(r3,1);
  delay(1000);
  digitalWrite(r3,0);
  delay(1000);
  Serial.println("Test Relay 4");
  digitalWrite(r4,1);
  delay(1000);
  digitalWrite(r4,0);
  delay(1000);
}
