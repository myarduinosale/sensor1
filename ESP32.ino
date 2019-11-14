
int LED1=0; // Nodemcu v2 ใช้ D0 , Nodemcu v3 ใช้ D4

void setup()
{
  pinMode(LED1, OUTPUT);
}
void loop()
{
  digitalWrite(LED1, HIGH);
  delay(250);
  digitalWrite(LED1, LOW);
  delay(250);
}
