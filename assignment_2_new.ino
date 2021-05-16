#include<Servo.h>
Servo myservo;
int echopin=4;
int trigpin=5;


void setup() {
pinMode(echopin,INPUT);
pinMode(trigpin,OUTPUT);
myservo.attach(13);
Serial.begin(9600);  
}

void loop() {
  digitalWrite(trigpin,HIGH);
  delay(1000);
  digitalWrite(trigpin,LOW);
  if(echopin<=50){
    digitalWrite(echopin,HIGH);
    myservo.write(180);
    delay(5000);
  }
  else{
    digitalWrite(echopin,LOW);
      myservo.write(0); 
  }
}
