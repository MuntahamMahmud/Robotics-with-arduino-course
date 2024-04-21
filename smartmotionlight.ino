
int pir=7;
int relay=9;
void setup() {
  Serial.begin(9600);
  pinMode(pir,INPUT);
  pinMode(relay,OUTPUT);
 

}

void loop() {
  if(digitalRead(pir)==HIGH){
    Serial.println("Motion detected");
    digitalWrite(relay,HIGH);

  }
else{
  Serial.println("Motion not detected");
  digitalWrite(relay,LOW);
}
}
