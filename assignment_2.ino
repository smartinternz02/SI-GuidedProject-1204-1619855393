#include<Servo.h>
Servo myservo;
int echopin=4;
int trigpin=5;



void setup() {
  // put your setup code here, to run once:
pinMode(echopin,INPUT);
pinMode(trigpin,OUTPUT);
Serial.begin(9600);
myservo.attach(13);

}

void loop() {
  // put your main code here, to run repeate
 
digitalRead(4,HIGH);
  int duration=pulseIn(echopin,HIGH);
  int distance=duration*0.0343/2;
  if{
    distance<=50;
  digitalWrite(5,HIGH);
  Serial.println("the distance is");
  Serial.println(distance);
int pos=0;pos<=180;pos+1;
myservo.write(pos);
Serial.println(pos);
delay(10000);
}
digitalRead(4,LOW);
else{
     distance>=50;
  digitalWrite(5,LOW);
  Serial.println("the distance is");
  Serial.println(distance);
int pos=180;pos>=0;pos-1;
myservo.write(pos);
Serial.println(pos);
delay(10000);
  
}

 
  
}
