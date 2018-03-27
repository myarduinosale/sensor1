#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
const int sensorPin= 0;
const int buzzerPin= 13;
int LPG_level;

void setup() {
Serial.begin(115200);
pinMode(sensorPin, INPUT);
pinMode(buzzerPin, OUTPUT);
lcd.begin();
lcd.backlight();

}
void loop() {
LPG_level= analogRead(sensorPin);
Serial.print("LPG: ");
Serial.println(LPG_level);
lcd.setCursor(0,0);
lcd.print("LPG: ");
lcd.setCursor(5,0);
lcd.print("                ");
lcd.setCursor(5,0);
lcd.print(LPG_level);
if(LPG_level > 200){ 
digitalWrite(buzzerPin, HIGH);
delay(200);
digitalWrite(buzzerPin, LOW);
delay(200);
digitalWrite(buzzerPin, HIGH);
}
else{
digitalWrite(buzzerPin, LOW);
}
delay(80);
}
