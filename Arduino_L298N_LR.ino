int MotorPin2 = 2;
int MotorPin3 = 3;
void setup() {
  pinMode(MotorPin2, OUTPUT);
  pinMode(MotorPin3, OUTPUT);
  Serial.begin(9600);
}

void loop() {

  digitalWrite(MotorPin2, HIGH);
  digitalWrite(MotorPin3, LOW);
  Serial.println("Motor Right");
  delay(2000);
  digitalWrite(MotorPin2, LOW);
  digitalWrite(MotorPin3, LOW);
  Serial.println("Motor STOP");
  delay(2000);
  digitalWrite(MotorPin2, LOW);
  digitalWrite(MotorPin3, HIGH);
  Serial.println("Motor Left");
  delay(2000);


}
