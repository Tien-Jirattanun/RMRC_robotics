///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int L11 = 27;
int L12 = 13;
int R11 = 19;
int R12 = 18;
int L21 = 14;
int L22 = 12;
int R21 = 4;
int R22 = 15;

void setup() 
{
  pinMode(L11,OUTPUT);
  pinMode(L12,OUTPUT);
  pinMode(R11,OUTPUT);
  pinMode(R12,OUTPUT);
}

void loop() 
{
  forward();
  delay(1000);   
  Stop();
  delay(1000);     
} 

void forward()
{
  digitalWrite(L11,HIGH);   
  digitalWrite(L12,LOW);      
  digitalWrite(R11,HIGH);                        
  digitalWrite(R12,LOW); 
}     

void Stop()
{
  digitalWrite(L11,LOW);   
  digitalWrite(L12,LOW);      
  digitalWrite(R11,LOW);                        
  digitalWrite(R12,LOW); 
} 

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int L11 = 27;
int L12 = 13;
int R11 = 19;
int R12 = 18;
int L21 = 14;
int L22 = 12;
int R21 = 4;
int R22 = 15;

void setup() 
{
  pinMode(L11,OUTPUT);
  pinMode(L12,OUTPUT);
  pinMode(R11,OUTPUT);
  pinMode(R12,OUTPUT);
}

void loop() 
{
  forward();
  delay(1000); 
  Stop();
  delay(100); 
  
  backward();
  delay(1000);
  Stop();
  delay(100);  
  
  left();
  delay(1000); 
  Stop();
  delay(100); 
  
  right();
  delay(1000);  
  Stop();
  delay(1000);     
} 

void forward()
{
  digitalWrite(L11,HIGH);   
  digitalWrite(L12,LOW);      
  digitalWrite(R11,HIGH);                        
  digitalWrite(R12,LOW); 
}     

void backward()
{
  digitalWrite(L11,LOW);   
  digitalWrite(L12,HIGH);      
  digitalWrite(R11,LOW);                        
  digitalWrite(R12,HIGH); 
}  

void right()
{
  digitalWrite(L11,HIGH);   
  digitalWrite(L12,LOW);      
  digitalWrite(R11,LOW);                        
  digitalWrite(R12,HIGH); 
}  

void left()
{
  digitalWrite(L11,LOW);   
  digitalWrite(L12,HIGH);      
  digitalWrite(R11,HIGH);                        
  digitalWrite(R12,LOW); 
}  

void Stop()
{
  digitalWrite(L11,LOW);   
  digitalWrite(L12,LOW);      
  digitalWrite(R11,LOW);                        
  digitalWrite(R12,LOW); 
}                                                                


//////////////////////////////////////////////////////////////////////////////////
#include <WiFi.h>
#include <WebServer.h>
char* ssid = "wifi1971";
char* password="66666666"; 
int led_pin =2;

WebServer server;

void setup() 
{
  pinMode(led_pin,OUTPUT);
  Serial.beHard resetting via RTS pin.gin(115200);
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
////////////////////////////////////////////////////////////////////////////////////////////
//full code 
 
#include <WiFi.h>
#include <WebServer.h>
char* ssid = "            ";
char* password="     "; 

int L11 = 27;
int L12 = 13;
int R11 = 19;
int R12 = 18;
int led_pin =2;

WebServer server;

void setup() 
{
  pinMode(L11,OUTPUT);
  pinMode(L12,OUTPUT);
  pinMode(R11,OUTPUT);
  pinMode(R12,OUTPUT);
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
  server.on("/forward",forward); 
  server.on("/backward",backward); 
  server.on("/left",left); 
  server.on("/right",right); 
  server.on("/stop",Stop);             
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

void forward()
{
  Stop2(); 
  digitalWrite(L11,HIGH);   
  digitalWrite(L12,LOW);      
  digitalWrite(R11,HIGH);                        
  digitalWrite(R12,LOW);
  server.send(204," ");  
}     

void backward()
{
  Stop2(); 
  digitalWrite(L11,LOW);   
  digitalWrite(L12,HIGH);      
  digitalWrite(R11,LOW);                        
  digitalWrite(R12,HIGH);
  server.send(204," ");   
}  

void right()
{
  Stop2(); 
  digitalWrite(L11,HIGH);   
  digitalWrite(L12,LOW);      
  digitalWrite(R11,LOW);                        
  digitalWrite(R12,HIGH);
  server.send(204," ");   
}  

void left()
{
  Stop2(); 
  digitalWrite(L11,LOW);   
  digitalWrite(L12,HIGH);      
  digitalWrite(R11,HIGH);                        
  digitalWrite(R12,LOW);
  server.send(204," ");   
}  

void Stop()
{
  digitalWrite(L11,LOW);   
  digitalWrite(L12,LOW);      
  digitalWrite(R11,LOW);                        
  digitalWrite(R12,LOW); 
  server.send(204," "); 
}

void Stop2()
{
  digitalWrite(L11,LOW);   
  digitalWrite(L12,LOW);      
  digitalWrite(R11,LOW);                        
  digitalWrite(R12,LOW);
  delay(20); 
}

//////////////////////////////////////////////////////////////////////////////////

//LEDC.ino
// setting PWM properties
const int freq = 5000;
const int ledChannel = 0;
const int resolution = 8;
#define ledPin 14
void setup(){
  // configure LED PWM functionalitites
  ledcSetup(ledChannel, freq, resolution);
  
  // attach the channel to the GPIO to be controlled
  ledcAttachPin(ledPin, ledChannel);
}
 
void loop(){
  // increase the LED brightness
  for(int dutyCycle = 0; dutyCycle <= 255; dutyCycle++){   
    // changing the LED brightness with PWM
    ledcWrite(ledChannel, dutyCycle);
    delay(15);
  }

  // decrease the LED brightness
  for(int dutyCycle = 255; dutyCycle >= 0; dutyCycle--){
    // changing the LED brightness with PWM
    ledcWrite(ledChannel, dutyCycle);   
    delay(15);
  }
}
////////////////////////////////////////////////////////////////////////////////
// blynk_botton.ino
/*************************************************************
  Download latest Blynk library here:
    https://github.com/blynkkk/blynk-library/releases/latest

  Blynk is a platform with iOS and Android apps to control
  Arduino, Raspberry Pi and the likes over the Internet.
  You can easily build graphic interfaces for all your
  projects by simply dragging and dropping widgets.

    Downloads, docs, tutorials: http://www.blynk.cc
    Sketch generator:           http://examples.blynk.cc
    Blynk community:            http://community.blynk.cc
    Follow us:                  http://www.fb.com/blynkapp
                                http://twitter.com/blynk_app

  Blynk library is licensed under MIT license
  This example code is in public domain.

 *************************************************************
  This example runs directly on ESP32 chip.

  Note: This requires ESP32 support package:
    https://github.com/espressif/arduino-esp32

  Please be sure to select the right ESP32 module
  in the Tools -> Board menu!

  Change WiFi ssid, pass, and Blynk auth token to run :)
  Feel free to apply it to any other example. It's simple!
 *************************************************************/

/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial

/* Fill-in your Template ID (only if using Blynk.Cloud) */

#define BLYNK_TEMPLATE_ID "TMPL3uTSQvYC"
#define BLYNK_DEVICE_NAME "ESP Rover"
#define BLYNK_AUTH_TOKEN "yvUf1Wh8pnRpCKaInFIOEtbLwpYXxd5d"

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = BLYNK_AUTH_TOKEN;

// Your WiFi credentials.
// Set password to "" for open networks.

char ssid[] = "POCO X3 NFC";
char pass[] = "99557242";

int L11 = 27;
int L12 = 13;
int R11 = 19;
int R12 = 18;
int L21 = 14;
int L22 = 12;
int R21 = 4;
int R22 = 15;
int FW,BW,LT,RT,ST,Speed=200;

BLYNK_WRITE(V0)
{
  FW=param.asInt();
  if(FW==1)
  {
   Serial.println("Forward");
   Stop2();
    //Blynk.virtualWrite(V0,0); FW=0;
    Blynk.virtualWrite(V1,0); BW=0;
    Blynk.virtualWrite(V2,0); LT=0;
    Blynk.virtualWrite(V3,0); RT=0;
    Blynk.virtualWrite(V4,0); ST=0;
  }else Stop();
}
BLYNK_WRITE(V1)
{
  BW=param.asInt();
  if(BW==1)
  {
   Serial.println("Backward");
   Stop2();
    Blynk.virtualWrite(V0,0); FW=0;
    //Blynk.virtualWrite(V1,0); BW=0;
    Blynk.virtualWrite(V2,0); LT=0;
    Blynk.virtualWrite(V3,0); RT=0;
    Blynk.virtualWrite(V4,0); ST=0;
  }else Stop();
}
BLYNK_WRITE(V2)
{
 
  LT=param.asInt();
  if(LT==1)
  {
   Serial.println("Left");
   Stop2();
   Blynk.virtualWrite(V0,0); FW=0;
   Blynk.virtualWrite(V1,0); BW=0;
   //Blynk.virtualWrite(V2,0); LT=0;
   Blynk.virtualWrite(V3,0); RT=0;
   Blynk.virtualWrite(V4,0); ST=0;
  }else Stop();
}
BLYNK_WRITE(V3)
{
  RT=param.asInt();
  if(RT==1)
  {
   Serial.println("Right");
   Stop2();
    Blynk.virtualWrite(V0,0); FW=0;
    Blynk.virtualWrite(V1,0); BW=0;
    Blynk.virtualWrite(V2,0); LT=0;
    //Blynk.virtualWrite(V3,0); RT=0;
    Blynk.virtualWrite(V4,0); ST=0;
  }else Stop();
}
BLYNK_WRITE(V4)
{
  ST=param.asInt();
  if(ST==1)
  {
   Serial.println("Stop");
   Stop2();
   Blynk.virtualWrite(V0,0); FW=0;
   Blynk.virtualWrite(V1,0); BW=0;
   Blynk.virtualWrite(V2,0); LT=0;
   Blynk.virtualWrite(V3,0); RT=0;
   //Blynk.virtualWrite(V4,0); ST=0;
  }else Stop();
}

BLYNK_WRITE(V5)
{
  Speed=param.asInt();
  Serial.print("Speed:");
  Serial.println(Speed);
}

void setup()
{
  // Debug console
  Serial.begin(115200);
  pinMode(L11,OUTPUT);
  pinMode(L12,OUTPUT);
  pinMode(R11,OUTPUT);
  pinMode(R12,OUTPUT);
  pinMode(L21,OUTPUT);
  pinMode(L22,OUTPUT);
  pinMode(R21,OUTPUT);
  pinMode(R22,OUTPUT);
  
  ledcSetup(0, 100, 8);
  ledcAttachPin(L11, 0);
  //ledcAttachPin(L21, 0); // For 4WD

  ledcSetup(1, 100, 8);
  ledcAttachPin(L12, 1);
  //ledcAttachPin(L22, 1);  // For 4WD

  ledcSetup(2, 100, 8);
  ledcAttachPin(R11, 2);
  //ledcAttachPin(R21, 2);  // For 4WD

  ledcSetup(3, 100, 8);
  ledcAttachPin(R12, 3);
  //ledcAttachPin(R22, 3);  // For 4WD
  
  Blynk.begin(auth, ssid, pass);
}

void loop()
{
  Blynk.run();
  if(FW==1) forward();
  if(BW==1) backward();
  if(LT==1) left();
  if(RT==1) right();
  if(ST==1) Stop();
  
}

void forward()
{
    ledcWrite(0, Speed);   
    ledcWrite(1, 0);   
    ledcWrite(2, Speed);
    ledcWrite(3, 0); 
}     

void backward()
{
    ledcWrite(0, 0);   
    ledcWrite(1, Speed);   
    ledcWrite(2, 0);
    ledcWrite(3, Speed); 
}  

void right()
{
    ledcWrite(0, Speed);   
    ledcWrite(1, 0);   
    ledcWrite(2, 0);
    ledcWrite(3, Speed); 
}  

void left()
{
    ledcWrite(0, 0);   
    ledcWrite(1, Speed);   
    ledcWrite(2, Speed);
    ledcWrite(3, 0); 
}  

void Stop()
{
    ledcWrite(0, 0);   
    ledcWrite(1, 0);   
    ledcWrite(2, 0);
    ledcWrite(3, 0); 
    delay(200);
    Blynk.virtualWrite(V4,0); ST=0;   
}          

void Stop2()
{ 
    ledcWrite(0, 0);   
    ledcWrite(1, 0);   
    ledcWrite(2, 0);
    ledcWrite(3, 0); 
    delay(20);                                                    
}

////////////////////////////////////////////////////////////////////////////////////////////////////////
