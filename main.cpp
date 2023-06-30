#include <Arduino.h>
#include <WiFi.h>

void ConnectToWiFi(const char* WIFI_NETWORK, const char* WIFI_PASSWORD);

int status = WL_IDLE_STATUS;


void setup() {
  Serial.begin(115200);

  char WiFi_ssid[32];
  char WiFi_pswd[32];

  Serial.print("\nAdd WiFi SSID: ");
  while(!Serial.available()){
    delay(1);
  }
  Serial.readBytes(WiFi_ssid, sizeof(WiFi_ssid));
  WiFi_ssid[sizeof(WiFi_ssid) - 1] = '\0';
  String ssidString = WiFi_ssid;
  ssidString.trim();  // Remove leading/trailing whitespaces
  ssidString.toCharArray(WiFi_ssid, sizeof(WiFi_ssid));
  Serial.print("\nWiFi_ssid: ");
  Serial.println(WiFi_ssid);

  Serial.print("\nAdd WiFi password: ");
  while(!Serial.available()){
    delay(1);
  }
  Serial.readBytes(WiFi_pswd, sizeof(WiFi_pswd));
  WiFi_pswd[sizeof(WiFi_pswd) - 1] = '\0';
  String pswdString = WiFi_pswd;
  pswdString.trim();  // Remove leading/trailing whitespaces
  pswdString.toCharArray(WiFi_pswd, sizeof(WiFi_pswd));
  Serial.print("\nWiFi_pswd: ");
  Serial.println(WiFi_pswd);

  ConnectToWiFi(WiFi_ssid, WiFi_pswd);
}


void loop() {
  Serial.print("\nIP address: ");
  Serial.println(WiFi.localIP());
  delay(1000);
}


void ConnectToWiFi(const char* WIFI_NETWORK, const char* WIFI_PASSWORD) {
  Serial.print("Connecting to WiFi");

  WiFi.mode(WIFI_STA);
  WiFi.begin(WIFI_NETWORK, WIFI_PASSWORD);
  
  while (WiFi.status() != WL_CONNECTED){
    Serial.print(".");
    delay(500);
  }

  if (WiFi.status() != WL_CONNECTED){
    Serial.println("Connection failed!");
  }
  else{
    Serial.print("\nConected to WiFi network with local IP address:");
    Serial.println(WiFi.localIP()); 
  }
}