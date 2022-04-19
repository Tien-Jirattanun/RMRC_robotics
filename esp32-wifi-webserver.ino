#include <WiFi.h>
#include <WebServer.h>
char* ssid = ",.";
char* password="22102548"; 
int led_pin =2;

WebServer server;

void setup() 
{
  pinMode(led_pin,OUTPUT);
  Serial.begin(115200);
  Serial.println("");
  WiFi.begin(ssid,password);
  Serial.println("initailizing WiFi connection");
  while(WiFi.status()!=WL_CONNECTED)
  {
    Serial.print(".");
    delay(500);
  }
  Serial.println("");
  Serial.print("IP Address: ");
  Serial.print(WiFi.localIP());

  server.on("/",[](){server.send(200,"text/plain","Hello World!");});  
  server.on("/toggle",toggleLED);       
  server.begin(); 
}

void loop() 
{
  server.handleClient();
}

void toggleLED()
{
  digitalWrite(led_pin,!digitalRead(led_pin));
  server.send(204," "); 
}
