long time ;
void setup()
{
  Serial.begin(9600);
}
void loop()
{

  time = millis();
  Serial.print("time: ");
  Serial.println(time);
  delay(1000);// หน่วงเวลา 1000ms
}
