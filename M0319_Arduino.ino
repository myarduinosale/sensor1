#include <SharpIR.h>
int led = 2;
int buzzer = 3;
#define IR A0
#define model 100500
/*
  2 to 15 cm GP2Y0A51SK0F  use 1080
  4 to 30 cm GP2Y0A41SK0F / GP2Y0AF30 series  use 430
  10 to 80 cm GP2Y0A21YK0F  use 1080
  10 to 150 cm GP2Y0A60SZLF use 10150
  20 to 150 cm GP2Y0A02YK0F use 20150
  100 to 550 cm GP2Y0A710K0F  use 100500
*/

SharpIR SharpIR(IR, model);
void setup() {
   pinMode(led, OUTPUT);
   pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  unsigned long startTime = millis();
  int dis = SharpIR.distance();
  Serial.print("distance: ");
  Serial.println(dis);
if (dis > 110){
    digitalWrite(led, LOW);
    digitalWrite(buzzer, HIGH);
   }
   if (dis < 110){
    digitalWrite(led, HIGH);
    digitalWrite(buzzer, LOW);
   }
   delay (500);
}
