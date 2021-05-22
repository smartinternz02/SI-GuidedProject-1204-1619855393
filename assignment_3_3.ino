
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define SCREEN_WIDTH 128 
#define SCREEN_HEIGHT 64
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);
#include "DHT.h"
#define DHTPIN 4   
#define DHTTYPE DHT11  
DHT dht(DHTPIN, DHTTYPE);
int a=15;
int h=4;
int t=4;


void setup() {
  Serial.begin(115200);
delay(2000);
Serial.println("oled test");
 dht.begin();
 delay(2000);
 pinMode(15,INPUT);
 pinMode(4,OUTPUT);
 pinMode(7,OUTPUT);
 pinMode(8,OUTPUT);
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 10);
  display.println("ldr value is");
  display.print(a);
  display.println("h =");
  display.print(h);
  display.println("t =");
  display.print(t);
  display.display();
  
 
}
void loop() {
  delay(2000);
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.print("%  Temperature: ");
  Serial.print(t);
  Serial.print("°C ");
  int a=analogRead(15);
  Serial.println(a);
  delay(2000);
  if(a<=20){
    digitalWrite(7,HIGH);
    Serial.println("lamp is turned off");
  }
  else{
    digitalWrite(7,LOW);
    Serial.println("lamp is turned on");
    
  }
  if(t>=25){
    digitalWrite(8,HIGH);
    Serial.println("fan is turned on");
  }
  else{
    digitalWrite(8,LOW);
    Serial.println("fan is turned off");
  }
  if(h>=50){
    digitalWrite(8,HIGH);
    Serial.println("fan is turned on"); 
  }
  else{
    digitalWrite(8,LOW);
    Serial.println("fan is turned off");
    
  }
}
