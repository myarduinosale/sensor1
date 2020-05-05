
// int sensitive = 100; // สำหรับ 20A
// int sensitive = 66; // สำหรับ 30A
int sensitive = 185; // สำหรับ 5A
int offset = 2504; // ค่าเริ่มต้น 2500 ปรับค่าตรงนี้เพื่อให้ค่ายังไม่มีโหลดเป็น 0.00
 
void setup() {
Serial.begin(9600);
}
 
void loop() {
double c = getCA();
Serial.println(c);
delay(1000);
}
 
// หาค่ากระแสเฉลี่ย
double getCA() {
int count = 200;
double sum = 0;
for (int i = 0; i < count; i++) {
sum += getC();
}
double val = sum / count;
return val;
}
// อ่านค่ากระแส
double getC() {
int a = analogRead(A0);
double v = (a / 1024.0) * 5000;
double c = (v - offset) / sensitive;
return c;
}
