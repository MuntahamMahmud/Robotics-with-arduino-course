#include <Servo.h>
Servo myservo;
int echo=8;
int trig=10;
void setup(){
Serial.begin(9600);
myservo.attach(7);
pinMode(echo,INPUT);
pinMode(trig,OUTPUT);
}
void loop(){
  if(distance_f(echo,trig)<30){
    myservo.write(90);
    Serial.print("movement detected");
  }
else {
  myservo.write(0);
  Serial.begin("movement not detected");

}
}
int distance_f(int echo,int trig){
digitalWrite(trig,LOW);
delay(2);
digitalWrite(trig,HIGH);
delay(10);
digitalWrite(trig,LOW);
delay(2);
int duration=pulseIn(echo,HIGH);
int distance =(duration*.034)/2;
return distance;

}