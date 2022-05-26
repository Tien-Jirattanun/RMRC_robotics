#include <ArduinoHardware.h>
#include <ros.h>
#include <sensor_msgs/Joy.h>
#include "Arduino.h"
#include "AX12A.h"


#define ENA 12
#define ENB 13
#define IN1 2
#define IN2 5
#define IN3 4
#define IN4 3




ros::NodeHandle nh;

sensor_msgs::Joy axe_msg;
sensor_msgs::Joy button_msg;
  
void roverCallBack(const sensor_msgs::Joy& joy_orig)
{

  double x = joy_orig.axes[1];
  double z = joy_orig.axes[0];

  double moveL = x-(z/2);
  double moveR = x+(z/2);

  if(moveL>0.0){
    analogWrite(ENA,moveL*255);
    digitalWrite(IN1,1);
    digitalWrite(IN2,0);
  }else if (moveL<0.0){
    analogWrite(ENA,abs(moveL)*255);
    digitalWrite(IN1,0);
    digitalWrite(IN2,1); 
  }else{ 
    analogWrite(ENA,0);
    digitalWrite(IN1,1);
    digitalWrite(IN2,1);
  }

  if (moveR>0.0){
    analogWrite(ENB,moveR*255);
    digitalWrite(IN3,0);
    digitalWrite(IN4,1);
  }else if (moveR<0.0){
    analogWrite(ENB,abs(moveR)*255);
    digitalWrite(IN3,1);
    digitalWrite(IN4,0);
  }else{ 
    analogWrite(ENB,0);
    digitalWrite(IN3,1);
    digitalWrite(IN4,1);
  }

  
}

ros::Subscriber <sensor_msgs::Joy> Motor("/joy_orig", roverCallBack);

void setup()
{
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  analogWrite(ENA, 0);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, HIGH);
  analogWrite(ENB, 0);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, HIGH);
  
  nh.getHardware()->setBaud(500000);
  nh.initNode();
  nh.subscribe(Motor);
} 

void loop()
{
  nh.spinOnce();
}
