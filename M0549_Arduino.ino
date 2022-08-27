int sensor1 = 2;
int sensor2 = 3;
int sensor3 = 4;
int sensor4 = 5;
int sensor5 = 6;
int buzzer = 7;

void setup() {
  pinMode(sensor1, INPUT);
  pinMode(sensor2, INPUT);
  pinMode(sensor3, INPUT);
  pinMode(sensor4, INPUT);
  pinMode(sensor5, INPUT);
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);

}

void loop() {
  int val1 = digitalRead(sensor1);
  int val2 = digitalRead(sensor2);
  int val3 = digitalRead(sensor3);
  int val4 = digitalRead(sensor4);
  int val5 = digitalRead(sensor5);

  Serial.print("ค่าแสง 1 : ");
  Serial.print(val1);
  Serial.print("     ค่าแสง 2 : ");
  Serial.print(val2);
  Serial.print("     ค่าแสง 3 : ");
  Serial.print(val3);
  Serial.print("     ค่าแสง 4 : ");
  Serial.print(val4);
  Serial.print("     ค่าแสง 5 : ");
  Serial.println(val5);

  if(val1 == 1 | val2 == 1 | val3 == 1 | val4 == 1 | val5 ==1){
    digitalWrite(buzzer, LOW);
  }
  else{
    digitalWrite(buzzer, HIGH);
  }

}
