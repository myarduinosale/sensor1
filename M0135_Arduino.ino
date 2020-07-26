#define pin A0
int led = 2;
int buzzer = 3;

void setup(){
   Serial.begin (9600);
   pinMode(pin, INPUT);
   pinMode(led, OUTPUT);
   pinMode(buzzer, OUTPUT);
}

void loop(){
   uint16_t value = analogRead (pin);
   double distance = get_IR (value);  //Convert the analog voltage to the distance
   Serial.println (value);  //Print the data to the arduino serial monitor
   Serial.print (distance);
   Serial.println (" cm");
   Serial.println ();
   if (distance > 10){
    digitalWrite(led, LOW);
    digitalWrite(buzzer, HIGH);
   }
   if (distance < 10){
    digitalWrite(led, HIGH);
    digitalWrite(buzzer, LOW);
   }
   delay (500);   //Delay 0.5s
}

//return distance (cm)
double get_IR(uint16_t value){
   if (value < 16)  value = 16;
   return 2076.0 / (value - 11.00);
}
