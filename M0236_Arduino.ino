int val = 0;
void setup() {
  Serial.begin(9600);
  pinMode(A0, INPUT);
}

void loop() {
  val = analogRead(A0);
  Serial.print(val);
  Serial.print(" mm\n");
  delay(300);
}
