int sensor1 = 2;
int sensor2 = 3;


void setup() {
  pinMode(sensor1, INPUT);
  pinMode(sensor2, INPUT);
  Serial.begin(9600);
}

void loop() {
  int val1 = digitalRead(sensor1);
  int val2 = digitalRead(sensor2);

  Serial.print ("ค่าแสง 1 : ");
  Serial.print(val1);
  Serial.print ("  ค่าแสง 2 : ");
  Serial.println(val2);

  delay(100);
}
