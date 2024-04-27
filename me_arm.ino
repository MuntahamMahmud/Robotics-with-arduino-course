#include<Servo.h>

Servo s1,s2,s3,s4,s5,s6;
int i1=90,i2=90,i3=90,i4=90,i5=90,i6=90;
char data;
//----------------------------------servo motor-----------------//
void setup()
     {
      s1.attach(3);
      s2.attach(4);
      s3.attach(5);
      s4.attach(6);
      s5.attach(7);
      s6.attach(8);

      s1.write(i1);
      s2.write(i2);
      s3.write(i3);
      s4.write(i4);
      s5.write(i5);
      s6.write(i6);
      Serial.begin(9600);

     }

void loop(){
if(Serial.available()>0) 
  {
  data=Serial.read();
  Serial.print(data);
  }


//----------------------------s1------------------------------------//
      if(data=='L')
      {
      i1++;
      runServo(s1,i1);
      Serial.println("S1 L");
      }
      if(data='R')
      {
        i1--;
        runServo(s2,i2);
        Serial.println("S1 R");
      }
//---------------------------s2------------------------------------//
       if(data=='F')
        {
                  i2++;
                  runServo(s2,i2);
                  Serial.println("S2 U");
        }
      if(data=='D')
      {
                i2--;
                runServo(s3,i2);
                Serial.println("S2 D");
      }
//--------------------s6---------------------------------//
       if(data=='V')
       {
            s6.write(93);
            Serial.println("S6 C");
       }
       if(data=='v')
       {
            s6.write(20);
            Serial.println("S6,0");
       }
//--------------------s4 and s5-----------------------------------//
if(data=='U'){
  while(1){
  data=Serial.read();
  Serial.print(data);
  
     if(data=='F'){
      i4++;
      runServo(s4,i4);
      Serial.print("s4 U");
     }
     if(data=='B'){
      i4--;
      runServo(s4,i4);
      Serial.println("s4 D");
     }
   if(data=='L'){
    i5++;
    runServo(s5,i5);
    Serial.println("s5 L");
   }
   if(data=='R')
   {
    i5--;
    runServo(s5,i5);
    Serial.println("s5 R");
   }
   if(data=='u'){
    break;
   }}

}

//--------------------------s3----------------
        if(data=='W'){
          while(1){
            data=Serial.read();
            Serial.println(data);
            if(data=='F'){
              i3++;
              runServo(s3,i3);
              Serial.println("s3,U");
            }
            if(data=='B'){
              i3--;
              runServo(s3,i3);
              Serial.println("s3,D");
            }
          if(data=='w'){
            break;
          }
          }
      }
}
void runServo(Servo &s, int &angle)
{
if(angle>=180){

  angle=180;
}
if(angle<0){
  angle=0;
}
s.write(angle);

}


