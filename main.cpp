#include <Arduino.h>
#include <WiFi.h>
#define WIFI_NETWORK "ARTINA WIFI" //my ssid
#define WIFI_PASSWORD "" //password

WiFiServer server(80); //Creates a server that listens for incoming connections on the specified port

int status = WL_IDLE_STATUS;

void ConnectToWiFi();

void setup() {
  Serial.begin(115200);
  ConnectToWiFi();
}

void loop() {
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
  Serial.print("MAC address: ");
  Serial.println(WiFi.macAddress());
  Serial.print("Server port: 80\n\n");
  server.println("ESP32 Around!!!");
  delay(1000);
}

void ConnectToWiFi() {
  Serial.print("Connecting to WiFi");

  WiFi.mode(WIFI_STA); //STATION MODE: it gives an IP address to the board from an existing network
  WiFi.begin(WIFI_NETWORK, WIFI_PASSWORD);
  
  while (WiFi.status() != WL_CONNECTED){
    Serial.print(".");
    delay(500);
  }

  if (WiFi.status() != WL_CONNECTED){
    Serial.println("Connection lost");
  }
  else{
    server.begin(); //Tells the server to begin listening for incoming connections
    Serial.print("\nConected to WiFi network with local IP address:");
    Serial.println(WiFi.localIP());
  }
}