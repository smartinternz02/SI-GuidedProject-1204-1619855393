#include <DHT.h>
#include <DHT_U.h>

#include "DHT.h"
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>



void setup() {
  // put your setup code here, to run once:
dht.begin();  
    Serial.begin(115200);
delay(2000);
Serial.println("oled test");
Serial.begin(9600);
Serial.println(F("DHTxx test!"));
 int a=h;
delay(2000);
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 10);
  display.println("humidity value is");
  display.println(a);
   display.display(); 
   int b=t;
   delay(2000);
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 10);
  display.println("temperature value is");
  display.println(b);
   display.display(); 
   
   


}

void loop() {
  // put your main code here, to run repeatedly:
delay(2000);
float h == dht.readHumidity();
Serial.print(F("Humidity: "));
Serial.println(h);
float t == dht.readTemperature();
Serial.print(F("%  Temperature: "));
Serial.println(t);
int a=analogRead(15);
Serial.println("the ldr value is");
Serial.println(a);
delay(2000);

}
