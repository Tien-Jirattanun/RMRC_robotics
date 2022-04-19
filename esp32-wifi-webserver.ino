#include <WiFi.h>
#include <WebServer.h>

#define MOTOR1_PIN1 27
#define MOTOR1_PIN2 13
#define MOTOR2_PIN1 19
#define MOTOR2_PIN2 18
#define MOTOR3_PIN1 14
#define MOTOR3_PIN2 12
#define MOTOR4_PIN1 4
#define MOTOR4_PIN2 15

char* ssid = "Mi";
char* password="11014test"; 
int led_pin =2;

WebServer server;

void setup() 
{
  pinMode(led_pin,OUTPUT);
  pinMode(MOTOR1_PIN1, OUTPUT);
  pinMode(MOTOR1_PIN2, OUTPUT);
  pinMode(MOTOR2_PIN1, OUTPUT);
  pinMode(MOTOR2_PIN2, OUTPUT);
  
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
  server.on("/w",moveForward);
  server.on("/a",moveLeft);
  server.on("/d",moveRight);
  server.on("/s",moveBackward);
  server.on("/z",motorStop);         
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

void moveForward(){
  digitalWrite(MOTOR1_PIN1, HIGH);
  digitalWrite(MOTOR1_PIN2, LOW);
  digitalWrite(MOTOR2_PIN1, HIGH);
  digitalWrite(MOTOR2_PIN2, LOW);
  server.send(204," "); 
}

void moveLeft(){
  digitalWrite(MOTOR1_PIN1, LOW);
  digitalWrite(MOTOR1_PIN2, HIGH);
  digitalWrite(MOTOR2_PIN1, HIGH);
  digitalWrite(MOTOR2_PIN2, LOW);
  server.send(204," "); 
}

void moveRight(){
  digitalWrite(MOTOR1_PIN1, HIGH);
  digitalWrite(MOTOR1_PIN2, LOW);
  digitalWrite(MOTOR2_PIN1, LOW);
  digitalWrite(MOTOR2_PIN2, HIGH);
  server.send(204," "); 
}

void moveBackward(){
  digitalWrite(MOTOR1_PIN1, LOW);
  digitalWrite(MOTOR1_PIN2, HIGH);
  digitalWrite(MOTOR2_PIN1, LOW);
  digitalWrite(MOTOR2_PIN2, HIGH);
  server.send(204," "); 
}

void motorStop(){
  digitalWrite(MOTOR1_PIN1, LOW);
  digitalWrite(MOTOR1_PIN2, LOW);
  digitalWrite(MOTOR2_PIN1, LOW);
  digitalWrite(MOTOR2_PIN2, LOW);
  server.send(204," "); 
}
