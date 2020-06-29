int sensor = 4;
int led = 3;
int buzzer = 2;
void setup() {
  pinMode(sensor, INPUT);
  pinMode(led, OUTPUT);
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
}
void loop() {
  sensor = analogRead(sensor);
  Serial.println(sensor);
  if (sensor < 600 ) {
    digitalWrite(led, LOW);
    digitalWrite(buzzer, HIGH);
  }
  if (sensor > 600 ) {
    Serial.println("Power ON");
    digitalWrite(led, HIGH);
    digitalWrite(buzzer, LOW);
    delay(250);
    digitalWrite(led, LOW);
    digitalWrite(buzzer, HIGH);
    delay(250);
    digitalWrite(led, HIGH);
    digitalWrite(buzzer, LOW);
    delay(250);
    digitalWrite(led, LOW);
    digitalWrite(buzzer, HIGH);
    delay(250);
    digitalWrite(led, HIGH);
    digitalWrite(buzzer, LOW);
    delay(250);
    digitalWrite(led, LOW);
    digitalWrite(buzzer, HIGH);
    delay(250);
    digitalWrite(led, HIGH);
    digitalWrite(buzzer, LOW);
    delay(250);
    digitalWrite(led, LOW);
    digitalWrite(buzzer, HIGH);
    delay(250);
    digitalWrite(led, HIGH);
    digitalWrite(buzzer, LOW);
    delay(250);
    Serial.println("Power OFF");
  }
  delay(250);
}
