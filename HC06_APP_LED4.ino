/*

 Software serial multple serial test


 Receives from the hardware serial, sends to software serial.

 Receives from software serial, sends to hardware serial.


 The circuit:

 * RX is digital pin 2 (connect to TX of other device)

 * TX is digital pin 3 (connect to RX of other device)


 Note:

 Not all pins on the Mega and Mega 2560 support change interrupts,

 so only the following can be used for RX:

 10, 11, 12, 13, 50, 51, 52, 53, 62, 63, 64, 65, 66, 67, 68, 69


 Not all pins on the Leonardo support change interrupts,

 so only the following can be used for RX:

 8, 9, 10, 11, 14 (MISO), 15 (SCK), 16 (MOSI).


 created back in the mists of time

 modified 25 May 2012

 by Tom Igoe

 based on Mikal Hart's example


 This example code is in the public domain.


 */

#include <SoftwareSerial.h>

int i =0;
char str[11]={'0','0','0','0','0','0','0','0','0','0','0'};
SoftwareSerial mySerial(2, 3); // RX, TX


void setup()

{
pinMode(8, OUTPUT);
pinMode(9, OUTPUT);
pinMode(10, OUTPUT);
pinMode(11, OUTPUT);
digitalWrite(8, HIGH);
digitalWrite(9, HIGH);
digitalWrite(10, HIGH);
digitalWrite(11, HIGH);
Serial.begin(9600);

while (!Serial) ;

mySerial.begin(9600);

}


void loop()

{

if (mySerial.available()){
//Serial.write(mySerial.read());
//Serial.println("ok");
i=i+1;
str[i]=mySerial.read();
//Serial.println(str[i]);
if(i ==9)
i=0;
if(str[5] == '1' && str[7] == '3')
digitalWrite(8, LOW);
if(str[5] == '1' && str[7] == '2')
digitalWrite(8, HIGH);
if(str[5] == '2' && str[7] == '3')
digitalWrite(9, LOW);
if(str[5] == '2' && str[7] == '2')
digitalWrite(9, HIGH);
if(str[5] == '3' && str[7] == '3')
digitalWrite(10, LOW);
if(str[5] == '3' && str[7] == '2')
digitalWrite(10, HIGH);
if(str[5] == '4' && str[7] == '3')
digitalWrite(11, LOW);
if(str[5] == '4' && str[7] == '2')
digitalWrite(11, HIGH);
}


if (Serial.available())

mySerial.write(Serial.read());

}
