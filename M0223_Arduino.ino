int sensor = A0;
int led = 2;
int buzzer = 3;
int val = 0;

void setup()
{
  Serial.begin(9600);
  pinMode(sensor, INPUT);
  pinMode(led, OUTPUT);
  pinMode(buzzer, OUTPUT);
}
void loop() {
  val = analogRead(sensor);
  Serial.println(val);
  delay(250);
  if (val < 500) {
    digitalWrite(led, LOW);
    digitalWrite(buzzer, HIGH);
  }
  if (val > 500) {
    Serial.println("Power ON");
    digitalWrite(led, HIGH);
    digitalWrite(buzzer, LOW);
    delay(1000);
    digitalWrite(led, HIGH);
    digitalWrite(buzzer, HIGH);
    delay(500);
    digitalWrite(led, HIGH);
    digitalWrite(buzzer, LOW);
    delay(1000);
    digitalWrite(led, HIGH);
    digitalWrite(buzzer, HIGH);
    delay(500);
    digitalWrite(led, HIGH);
    digitalWrite(buzzer, LOW);
    delay(1000);
    digitalWrite(led, HIGH);
    digitalWrite(buzzer, HIGH);
    delay(10000);
    Serial.println("Power OFF");
  }
}
