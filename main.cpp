#include <Arduino.h>
#include <WiFi.h>
#define WIFI_NETWORK "MyrDyn" //my ssid
#define WIFI_PASSWORD "M90b53M98pj62@" //password

void ConnectToWiFi();

void setup() {
  Serial.begin(115200);
  ConnectToWiFi();
}

void loop() {
}

void ConnectToWiFi() {
  Serial.print("Connecting to WiFi");

  WiFi.mode(WIFI_STA); //it gives an IP address to the board from an existing network
  WiFi.begin(WIFI_NETWORK, WIFI_PASSWORD);
  
  while (WiFi.status() != WL_CONNECTED){
    Serial.print(".");
    delay(500);
  }

  if (WiFi.status() != WL_CONNECTED){
    Serial.println("Connection lost");
  }
  else{
    Serial.print("\nConected to WiFi network with local IP address:");
    Serial.println(WiFi.localIP()); 
  }
}