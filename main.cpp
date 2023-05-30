#include <Arduino.h>
#include <WiFi.h>

#define WIFI_NETWORK "ARTINA WIFI" //my ssid
#define WIFI_PASSWORD "" //password

IPAddress staticIP(192, 168, 0, 205); // This is the way to assign IP addresses. You need them as IPAddress objects to pass them in config
IPAddress gateway(192, 168, 0, 1);         
IPAddress subnet(255, 255, 255, 0);  


int status = WL_IDLE_STATUS;

void ConnectToWiFi();

void setup() {
  Serial.begin(115200);
  ConnectToWiFi();
}

void loop() {
  Serial.println(WiFi.macAddress());
  Serial.println(WiFi.localIP());
  delay(1000);
}

void ConnectToWiFi() {
  Serial.print("Connecting to WiFi");

  WiFi.mode(WIFI_STA); //it gives an IP address to the board from an existing network
  //good practise is to call that before WiFi.begign or else it begins with DHCP
  WiFi.config(staticIP, gateway, subnet); //I think the order of the objects is irrelevant

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