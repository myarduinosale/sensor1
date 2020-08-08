#include <Servo.h>
int servo = 6;
Servo myservo;
int analogPin = 5;
int val = 0;
void setup() {
myservo.attach(servo);
  Serial.begin(9600);
}

void loop() {
  val = analogRead(analogPin);
  Serial.print("val = ");
  Serial.println(val);
  val = val/6;
  myservo.write(val); 
  delay(100);
 
}
