int ch1; // ตัวแปรของ channel
int ch2;
int ch3;
int ch4;
int ch5;
int ch6;

void setup() {

pinMode(5, INPUT);
pinMode(6, INPUT);
pinMode(7, INPUT);
pinMode(8, INPUT);
pinMode(9, INPUT);
pinMode(10, INPUT);

Serial.begin(9600);

}

void loop() {

ch1 = pulseIn(5, HIGH, 25000); // อ่านค่าความกว้างของสัญญาณของแต่ละ Channel
ch2 = pulseIn(6, HIGH, 25000); 
ch3 = pulseIn(7, HIGH, 25000);
ch4 = pulseIn(8, HIGH, 25000);
ch5 = pulseIn(9, HIGH, 25000);
ch6 = pulseIn(10, HIGH, 25000);

Serial.print("Channel 1:"); // Print the value of
Serial.println(ch1); // each channel

Serial.print("Channel 2:");
Serial.println(ch2);

Serial.print("Channel 3:");
Serial.println(ch3);

Serial.print("Channel 4:");
Serial.println(ch4);

Serial.print("Channel 5:");
Serial.println(ch5);

Serial.print("Channel 6:");
Serial.println(ch6);

Serial.println("");
}
