int Sen = 5; // ประกาศตัวแปรให้เซ็นเซอร์อยู่ที่ ขาที่ A5
int val = 0;
int LED = 2; // ประกาศตัวแปรให้ LED อยู่ที่ ขาที่ 2
int I = 0;
void setup() {
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
}
void loop() {
  val = analogRead(Sen);
  Serial.println(val);
  //Serial.println(I);
  if (val > 700 || val < 300  ) {
    I = I + 1;
    
  }
  if (I == 1) {
    digitalWrite(LED, HIGH); 
    Serial.println("LED_ON");
  }
  if (I == 2) {
    digitalWrite(LED, LOW); 
    Serial.println("LED_OFF");
    I = 0;
  }
  delay(200);
} 
