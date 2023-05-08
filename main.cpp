#include <Arduino.h>
#include <WiFi.h>

const char* ssid = "TP-LINK_8EDC_5G"; //my ssid
const char* password = "87312324"; //password


void setup() {
  Serial.begin(115200);
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
    Serial.println("Ping me!");
    delay(5000);
  }
  else{
    Serial.println("Connection lost");
  }
}