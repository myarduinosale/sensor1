#include <Wire.h>
#include <MMA8453_n0m1.h>

MMA8453_n0m1 accel;

void setup()
{
  Serial.begin(9600);
  accel.setI2CAddr(0x1D); //change your device address if necessary, default is 0x1C
  accel.dataMode(true, 2); //enable highRes 10bit, 2g range [2g,4g,8g]
  Serial.println("MMA8453_n0m1 library");
  Serial.println("XYZ Data Example");

}

void loop()
{
  accel.update();

  Serial.print("x: ");
  Serial.print(accel.x());
  Serial.print(" y: ");
  Serial.print(accel.y());
  Serial.print(" z: ");
  Serial.println(accel.z());

}
