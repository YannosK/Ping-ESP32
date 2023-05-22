#include <Arduino.h>
#include <WiFi.h>
#define ledPIN 5

const char* ssid = "MyrDyn"; //my ssid
const char* password = "M90b53M98pj62@"; //password


void setup() {
  Serial.begin(115200);
  pinMode(ledPIN,OUTPUT);
  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi");
  
  while (WiFi.status() != WL_CONNECTED){
    Serial.print(".");
    delay(500);
  }
  Serial.print("\nConected to WiFi network with local IP address:");
  Serial.println(WiFi.localIP());
}

void loop() {  
  if (WiFi.status() == WL_CONNECTED){
    Serial.println("LED ON");
    digitalWrite(ledPIN,HIGH);
    delay(1000);
    Serial.println("LED OFF");
    digitalWrite(ledPIN,LOW);
    delay(1000);
  }
  else{
    Serial.println("Connection lost");
  }
}