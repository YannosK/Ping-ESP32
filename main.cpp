//this spawned a new project called "WiFi ChatServer"
#include <Arduino.h>
#include <WiFi.h>



void ConnectToWiFi(const char* WIFI_NETWORK, const char* WIFI_PASSWORD);
//void WifiCredentialsViaSerial(char WiFi_network[], char WiFi_password[]);
void ConnectToServer(IPAddress server);

int status = WL_IDLE_STATUS;

IPAddress server(192, 168, 1, 44);

// Initialize the Ethernet client library
// with the IP address and port of the server
// that you want to connect to (port 80 is default for HTTP):
WiFiClient client;

void setup() {
  Serial.begin(115200);

  char WiFi_ssid[32] = "HOME_EXT";
  char WiFi_pswd[32] = "123456789";

  //WifiCredentialsViaSerial(WiFi_ssid, WiFi_pswd);

  ConnectToWiFi(WiFi_ssid, WiFi_pswd);

  ConnectToServer(server);
}


void loop() {
  /*
  Serial.print("\nIP address: ");
  Serial.println(WiFi.localIP());
  delay(1000);
  */

  while(client.connected()){
    // if there are incoming bytes available from the server, read them and print them:
    while(client.available()) {
      char c = client.read();
      Serial.write(c);
    }

    while(Serial.available())
    {
      String msg_to_client = Serial.readString();
      client.print(msg_to_client);
    }   

    //Serial.println();

    //delay(1000);

    //client.stop();
  }

  Serial.println();
  Serial.println("disconnecting from server.");
  //client.stop();

  while(true)
  {}
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

/*
void WifiCredentialsViaSerial(char WiFi_network[], char WiFi_password[]) {
  Serial.print("\nAdd WiFi SSID: ");
  while(!Serial.available()){
    delay(1);
  }
  Serial.readBytes(WiFi_network, 32);
  WiFi_network[31] = '\0';
  String ssidString = WiFi_network;
  ssidString.trim();  
  ssidString.toCharArray(WiFi_network, 32);
  Serial.print("\nWiFi_network: ");
  Serial.println(WiFi_network);

  Serial.print("\nAdd WiFi password: ");
  while(!Serial.available()){
    delay(1);
  }
  Serial.readBytes(WiFi_password, 32);
  WiFi_password[31] = '\0';
  String pswdString = WiFi_password;
  pswdString.trim(); 
  pswdString.toCharArray(WiFi_password, 32);
  Serial.print("\nWiFi_password: ");
  Serial.println(WiFi_password);
}
*/

void ConnectToServer(IPAddress server)
{
  Serial.println("\nStarting connection to server...");
  // if you get a connection, report back via serial:
  client.connect(server, 80);

  //affirmation that we connected indeed
  if (client.connected()) {
    Serial.println("connected to server");
  }  
}