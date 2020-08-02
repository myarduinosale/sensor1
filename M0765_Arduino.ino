#include <Wire.h>
#include <VL53L0X.h>
int led = 3;
int buzzer = 4;

VL53L0X sensor;

void setup()
{
  Serial.begin(9600);
  Wire.begin();
  pinMode (led, OUTPUT);
  pinMode (buzzer, OUTPUT);
  sensor.init();
  sensor.setTimeout(500);
  sensor.startContinuous();
}

void loop() {
  Serial.print(sensor.readRangeContinuousMillimeters());
  if (sensor.timeoutOccurred()) {
    Serial.print(" TIMEOUT");
  }
  if (sensor.readRangeContinuousMillimeters()< 50) {
    digitalWrite(led, HIGH);
    digitalWrite(buzzer, LOW);
  }
  if (sensor.readRangeContinuousMillimeters()> 50) {
    digitalWrite(led,LOW);
    digitalWrite(buzzer, HIGH);
  }
  Serial.println();
}
