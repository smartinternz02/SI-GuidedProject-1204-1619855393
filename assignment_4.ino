#include "BluetoothSerial.h"
BluetoothSerial SerialBT;
int echopin=4;
int trigpin=5;
#define led 13

void setup() {
  Serial.begin(115200);
  delay(3000);
  Serial.println("data");
  SerialBT.begin("ESP32test"); //Bluetooth device name
  Serial.println("The device has started, now you can pair it with bluetooth!");
  pinMode(echopin,INPUT);
  pinMode(trigpin,OUTPUT);
  pinMode(13,OUTPUT); 
}

void loop() {

  delay(2000);
  digitalWrite(trigpin,HIGH);
  delay(2000);
  digitalWrite(trigpin,LOW);
  int duration=pulseIn(echopin,HIGH);
  int distance=duration*0.0343/2;
  if (Serial.available()) {
    SerialBT.write(Serial.read());
  }
  if (SerialBT.available()) {
    Serial.write(SerialBT.read());
  } 
  if(distance<=15){
    Serial.println("full water PUMP OFF");
    digitalWrite(13,LOW);
  }
    else{
      Serial.println("no water PUMP ON");
      digitalWrite(13,HIGH);
      
    } 
  
}
