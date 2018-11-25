int out1 = 4;
int out2 = 5; 
int out3 = 6; 
int out4 = 7; 
int LEDF = 8;
char valuehc06 = '0';
#include <SoftwareSerial.h>
SoftwareSerial mySerial(2, 3); // RX, TX
void setup()
{
Serial.begin(9600);
while (!Serial) ;
mySerial.begin(9600);
pinMode(out1, OUTPUT);
pinMode(out2, OUTPUT); 
pinMode(out3, OUTPUT); 
pinMode(out4, OUTPUT); 
pinMode(LEDF, OUTPUT); 
digitalWrite(out1,LOW);
digitalWrite(out2,LOW);
digitalWrite(out3,LOW);
digitalWrite(out4,LOW);
digitalWrite(LEDF,LOW);
}
void loop()
{
if (mySerial.available()){
//Serial.write(mySerial.read());
valuehc06 = mySerial.read();
Serial.print("valuehc06:");
Serial.println(valuehc06);
}
if (Serial.available())
mySerial.write(Serial.read());
if (valuehc06 == 'F'){//เดินหน้า
  digitalWrite(out1,LOW);
digitalWrite(out2,HIGH);
digitalWrite(out3,HIGH);
digitalWrite(out4,LOW);
  Serial.print("OK_F");
}
if (valuehc06 == 'G'){//ถอยหลัง
  digitalWrite(out1,HIGH);
digitalWrite(out2,LOW);
digitalWrite(out3,LOW);
digitalWrite(out4,HIGH);
  Serial.print("OK_G");
}
if (valuehc06 == 'L'){//เลี้ยวซ้าย
  digitalWrite(out1,LOW);
digitalWrite(out2,HIGH);
digitalWrite(out3,LOW);
digitalWrite(out4,LOW);
  Serial.print("OK_L");
}
if (valuehc06 == 'R'){//เลี้ยวขวา
  digitalWrite(out1,LOW);
digitalWrite(out2,LOW);
digitalWrite(out3,HIGH);
digitalWrite(out4,LOW);
  Serial.print("OK_R");
}
if (valuehc06 == 'S'){
  digitalWrite(out1,LOW);
digitalWrite(out2,LOW);
digitalWrite(out3,LOW);
digitalWrite(out4,LOW);
  Serial.print("OK_S");
}
if (valuehc06 == 'm'){//LEDFOFF
digitalWrite(LEDF,HIGH);
  Serial.print("OK_LEDFON");
}
if (valuehc06 == 'M'){//LEDFON
digitalWrite(LEDF,LOW);
  Serial.print("OK_LEDFOFF");
}

}


