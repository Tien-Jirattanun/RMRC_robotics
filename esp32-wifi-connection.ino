#include <WiFi.h>
#include <WebServer.h>

char* ssid = "eleclink";
char* password = "elec1234";

void setup() {
  
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("");
  WiFi.begin(ssid, password);
  Serial.println("initailizing WiFi connection");
  while(WiFi.status() != WL_CONNECTED){
    Serial.print(".");
    delay(500);
  }
  Serial.println("");
  Serial.print("IP Address: ");
  Serial.print(WiFi.localIP());


  
}

void loop() {
  // put your main code here, to run repeatedly:

}
