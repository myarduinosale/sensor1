int sensor = A0;
int led = 3;
int buzzer = 2;
int val = 0;

void setup() {
  Serial.begin(9600);
  pinMode(sensor, INPUT);
  pinMode(led, OUTPUT);
  pinMode(buzzer, OUTPUT);
}

void loop() {
  val = analogRead(sensor);
  Serial.println(val);
  if (val > 100){
    digitalWrite(led, LOW);
    digitalWrite(buzzer, HIGH);
    Serial.println("No Water");
  }
  if (val < 100){
    digitalWrite(led, HIGH);
    digitalWrite(buzzer, LOW);
    Serial.println("Detected Water");
  }
  delay(500);
}
