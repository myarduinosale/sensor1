int led1 = 2; // กำหนดขาใช้งาน 
int led2 = 3; 
int led3 = 4; 
int led4 = 5; 
int led5 = 6; 
void setup() 
{ 
pinMode(led1, OUTPUT); // กำหนดขาทำหน้าที่ให้ขา 2 เป็น OUTPUT 
pinMode(led2, OUTPUT); // กำหนดขาทำหน้าที่ให้ขา 3 เป็น OUTPUT 
pinMode(led3, OUTPUT); // กำหนดขาทำหน้าที่ให้ขา 4 เป็น OUTPUT 
pinMode(led4, OUTPUT); // กำหนดขาทำหน้าที่ให้ขา 5 เป็น OUTPUT 
pinMode(led5, OUTPUT); // กำหนดขาทำหน้าที่ให้ขา 6 เป็น OUTPUT 

digitalWrite(led5,LOW); 
digitalWrite(led5,LOW); 
digitalWrite(led5,LOW); 
digitalWrite(led5,LOW); 
digitalWrite(led5,LOW); 
} 
void loop() 
{ 
digitalWrite(led1,HIGH); // ไฟ LED 1 ติด 50 ms 
delay(50); 
digitalWrite(led1,LOW); // ไฟ LED 1 ดับ50 ms 
delay(50); 
digitalWrite(led2,HIGH); 
delay(50); 
digitalWrite(led2,LOW); 
delay(50); 
digitalWrite(led3,HIGH); 
delay(50); 
digitalWrite(led3,LOW); 
delay(50); 
digitalWrite(led4,HIGH); 
delay(50); 
digitalWrite(led4,LOW); 
delay(50); 
digitalWrite(led5,HIGH); 
delay(50); 
digitalWrite(led5,LOW); 
delay(100); 
} 
