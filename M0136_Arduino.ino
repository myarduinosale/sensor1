#define pin A0
int led = 2;
int buzz = 3;

void setup() {
  Serial.begin (9600);
  pinMode(pin, INPUT);
  pinMode(led, OUTPUT);
  pinMode(buzz, OUTPUT);
}

void loop() {
  uint16_t value = analogRead (pin);
  double distance = get_IR (value);
  Serial.print (distance);
  Serial.println (" cm");
  Serial.println ();
  if (distance > 20) {
    digitalWrite(led, LOW);
    digitalWrite(buzz, HIGH);
  }
  else {
    digitalWrite(led, HIGH);
    digitalWrite(buzz, LOW);
  }
  delay (100);
}

//return distance (cm)
double get_IR(uint16_t value) {
  if (value < 16)  value = 16;
  return 9462.0 / (value - 16.92);
}
