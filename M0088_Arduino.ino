int buzzer = 2;
int analogPin = A0;
int val = 0;

void setup() { 
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600); 
}   

void loop() { 
  val = analogRead(analogPin);
  Serial.println(val); 
  if (val > 400){
    digitalWrite(buzzer, LOW);
  }
  else {
    digitalWrite(buzzer, HIGH);
  }
  delay(100);
}
