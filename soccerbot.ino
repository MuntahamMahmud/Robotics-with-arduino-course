//right motor: ren 10 len 11,rpwm 5, lpwm 6
//left motor; ren 7,len 8,rpwm 9,lpwm 10

int speeds;
char data;
  #define rm_ren 11
  #define rm_len 12
  #define rm_rpwm 5
  #define rm_lpwm 6
  #define lm_ren 7
  #define lm_len 8
  #define lm_rpwm 9
  #define lm_lpwm 10
        void forward();
        void backward();
        void rightward();
        void leftward();
        void stop();


void setup() {
  // put your setup code here, to run once:
          pinMode(rm_ren,OUTPUT);
          pinMode(rm_len,OUTPUT);
          pinMode(rm_rpwm,OUTPUT);
          pinMode(rm_lpwm,OUTPUT);
            pinMode(lm_ren,OUTPUT);
            pinMode(lm_len,OUTPUT);
            pinMode(lm_rpwm,OUTPUT);
            pinMode(lm_lpwm,OUTPUT);
          Serial.begin(9600);
}

//must open bluetooths module tx rx pin while uploading
void loop() {
if(Serial.available()){
data=Serial.read();
if(data=='0' || data=='1' || data=='2' || data=='3' || data=='4' || data=='5' || data=='6' || data=='7' || data=='8' || data=='9')
{
  int value=(int)data; //this is called typecasting
  speeds=value*27;
}
if(data=='F'){
  forward();
  Serial.println("F");

}
if(data=='B'){
  backward();
  Serial.println("B");
  
            }
if(data=='R'){
  rightward();
  Serial.println("R");
  
            }
if(data=='L'){
      leftward();
      Serial.println("L");
            }
    if(data=='S'){
      stop();
      Serial.println("STOP");
                  }
                  

}
}

/////-------------------------------- side commands-------------------------/////
void forward(){
      digitalWrite(rm_ren,HIGH);
      digitalWrite(rm_len,HIGH);
      analogWrite(rm_rpwm,speeds);
      analogWrite(rm_lpwm,0);
        digitalWrite(lm_ren,HIGH);
        digitalWrite(lm_len,HIGH);
        analogWrite(lm_rpwm,speeds);
        analogWrite(lm_lpwm,0);

}
void backward(){

      digitalWrite(rm_ren,HIGH);
      digitalWrite(rm_len,HIGH);
      analogWrite(rm_rpwm,0);
      analogWrite(rm_lpwm,speeds);
        digitalWrite(lm_ren,HIGH);
        digitalWrite(lm_len,HIGH);
        analogWrite(lm_rpwm,0);
        analogWrite(lm_lpwm,speeds);

}
void rightward(){ //jedike turn nite chai shediker motor ke ulta dike ghurabo
      digitalWrite(rm_ren,HIGH);
      digitalWrite(rm_len,HIGH);
      analogWrite(rm_rpwm,0);
      analogWrite(rm_lpwm,speeds);
        digitalWrite(lm_ren,HIGH);
        digitalWrite(lm_len,HIGH);
        analogWrite(lm_rpwm,speeds);
        analogWrite(lm_lpwm,0);

}
void leftward(){
      digitalWrite(rm_ren,HIGH);
      digitalWrite(rm_len,HIGH);
      analogWrite(rm_rpwm,speeds);
      analogWrite(rm_lpwm,0);
        digitalWrite(lm_ren,HIGH);
        digitalWrite(lm_len,HIGH);
        analogWrite(lm_rpwm,0);
        analogWrite(lm_lpwm,speeds);

}
void stop(){
    digitalWrite(rm_ren,LOW);
    digitalWrite(rm_len,LOW);
    digitalWrite(lm_ren,LOW);
    digitalWrite(lm_len,LOW);       
}
/////////////////--------------------------------//////////////////////////
