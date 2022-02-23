#include <SoftwareSerial.h>
SoftwareSerial mySerial(11,10); 

unsigned char S1[4]={};// I am not sure what is the use of the array in this code.
int i,SensorMM,sum,SensorCM,Inch,Approx;

void setup()
{
 Serial.begin(57600);
 mySerial.begin(9600);
}

void loop()
{
    do{
     for(i=0;i<4;i++)
          {
           S1[i]= mySerial.read();
          }
      }while(mySerial.read()==0xff);

     mySerial.flush();

    if(S1[0]==0xff)
     {
        sum=(S1[0]+S1[1]+S1[2])&0x00FF;
       
    if(sum==S1[3])
       {
        SensorMM=(S1[1]<<8)+S1[2];
       
    if(SensorMM>280)
          {
              SensorCM=SensorMM/10;
              Inch=SensorCM/2.54;//I want the output in Inch in the serial monitor.
              Approx = (int)(Inch+0.5);// I just want a single-digit value (without and decimal) in the serial monitor. Here I am rounding the value to the nearest one.  
              Serial.print("ระยะทาง ");
              Serial.print(Approx*2.54);
              Serial.println(" CM"); 
              delay(100);
           }else 
               { 
                 Serial.println("Too Close");      
               }
         }else Serial.println("ERROR");
      }
       delay(150);
}
