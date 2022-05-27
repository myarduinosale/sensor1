int fsrPin = 0;
int fsrReading;
int led1 = 2;
int led2 = 3;

void setup(void) {
  pinMode (led1, OUTPUT);
  pinMode (led2, OUTPUT);
  Serial.begin(9600);
}

void loop(void) {
  fsrReading = analogRead(fsrPin);
  Serial.print("ค่าสัญญาณ Analog = ");
  Serial.print(fsrReading);

  if (fsrReading < 10) {
    Serial.println(" - แรงกดมากเกินไป");
  }
  else if (fsrReading < 200) {
    Serial.println(" - แรงกดมาก");
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
  }
  else if (fsrReading < 500) {   
    Serial.println(" - แรงกดปานกลาง");
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
  }
  else if (fsrReading < 800) {
    Serial.println(" - แรงกดน้อย");
    digitalWrite(led1, LOW);
    digitalWrite(led2, HIGH);
  }
  else {
    Serial.println(" - สัมผัสเบาๆ");
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
  }
  delay(1000);
}
