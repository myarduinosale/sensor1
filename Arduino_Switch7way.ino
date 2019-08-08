void setup() {
  for (int i = 7; i <= 13; i++) {
    pinMode(i, INPUT_PULLUP);
  }
  Serial.begin(9600);
  Serial.println("ArduinoAll TEST");
}

void loop() {

  if (digitalRead(13) == 0) {
    Serial.println("UP");
  } else if (digitalRead(12) == 0) {
    Serial.println("DOWN");
  } else if (digitalRead(11) == 0) {
    Serial.println("LEFT");
  } else if (digitalRead(10) == 0) {
    Serial.println("RIGHT");
  } else if (digitalRead(9) == 0) {
    Serial.println("MID");
  } else if (digitalRead(8) == 0) {
    Serial.println("SET");
  } else if (digitalRead(7) == 0) {
    Serial.println("RESET");
  }
  delay(200);

}
