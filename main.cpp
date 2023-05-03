#include <Arduino.h>
#include <WiFi.h>

const char* ssid = "ARTINA WIFI"; //my ssid
const char* password = ""; //password


void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi");
  
  while (WiFi.status() != WL_CONNECTED){
    Serial.print(".");
    delay(500);
  }
  Serial.print("\nConected\n");
}

void loop() {
  if (WiFi.status() == WL_CONNECTED){
    Serial.println("Ping me!");
    delay(5000);
  }
  else{
    Serial.println("Connection lost");
  }