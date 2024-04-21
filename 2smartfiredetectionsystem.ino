void setup() {
  // put your setup codp here, to run once:
Serial.begin(9600);

pinMode(2,INPUT);
pinMode(7,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
if(digitalRead(2)==0){
  Serial.println("fire detected");
  delay(1000);
  digitalWrite(7,HIGH);

}
else{
  Serial.println("fire not detected");
  delay(1000);
  digitalWrite(7,LOW);
}
if (analogRead(A0)>100){

  Serial.println("  smoke detected");
  delay(1000);
  digitalWrite(7,HIGH);
}
else{
  Serial.println(" smoke not detected");
delay(1000);
digitalWrite(7,LOW);
}
Serial.println("");

}
