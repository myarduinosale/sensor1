#include <Wire.h>
#include <Adafruit_SI1145.h>

Adafruit_SI1145 uv = Adafruit_SI1145();

void setup() {
  Serial.begin(9600);
  while (!uv.begin());
}

void loop() {
  Serial.print("Vis: ");
  Serial.print(uv.readVisible());
  Serial.print("mW/cm^2");
  Serial.print("     IR: ");
  Serial.print(uv.readIR());
  Serial.print("mW/cm^2");

  float UVintensity = uv.readUV();
  // the intensity is multiplied by 100 so to get the
  // integer intensity, divide by 100!
  UVintensity /= 100.0;
  Serial.print("     UV: ");
  Serial.print(UVintensity);
  Serial.println("mW/cm^2");

  delay(200);
}
