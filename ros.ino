#include <ArduinoHardware.h>
#include <ros.h> 
#include <sensor_msgs/Joy.h> 

#define ENA 5
#define ENB 6
#define IN1 8
#define IN2 10
#define IN3 9
#define IN4 11

ros::NodeHandle nh;

sensor_msgs::Joy axe_msg;
sensor_msgs::Joy button_msg;

void roverCallBack(const sensor_msgs::Joy& joy_orig)
{

	double y = joy_orig.axes[1];
  double x = joy_orig.axes[0];

	double moveL = y-(x/2);
	double moveR = y+(x/2);

  //move forward
  if(y > 0 && x = 0){
    analogWrite(ENA,y*100);
    analogWrite(ENB,y*100);
    digitalWrite(IN1,1); 
    digitalWrite(IN2,0);
    digitalWrite(IN3,1);
    digitalWrite(IN5,0);
  }

  //move back ward
  else if(y < 0 && x = 0){
    y *= -1;
    analogWrite(ENA,y*100);
    analogWrite(ENB,y*100);
    digitalWrite(IN1,0); 
    digitalWrite(IN2,1);
    digitalWrite(IN3,0);
    digitalWrite(IN5,1);
  }

  //move left
  else if(y = 0 && x > 0){
    analogWrite(ENA*100);
    analogWrite(ENB,y*100);
    digitalWrite(IN1,1); 
    digitalWrite(IN2,0);
    digitalWrite(IN3,0);
    digitalWrite(IN5,1);
  }

  //move right
  else if(y = 0 && x < 0){
    x *= -1;
    analogWrite(ENA,y*100);
    analogWrite(ENB,y*100);
    digitalWrite(IN1,0); 
    digitalWrite(IN2,1);
    digitalWrite(IN3,1);
    digitalWrite(IN5,0);
  }
  
  else {
    digitalWrite(IN1,0); 
    digitalWrite(IN2,0);
    digitalWrite(IN3,0);
    digitalWrite(IN5,0);
  }


  
//  if (moveR>0.0){
//    analogWrite(ENA,max(min(moveR*100,60),35));
//    digitalWrite(IN1,0);
//    digitalWrite(IN2,1);
//  }
//  else if (moveR<0.0){
//    analogWrite(ENA,max(min(abs(moveR)*100,60),35));
//    digitalWrite(IN1,1);
//    digitalWrite(IN2,0);
//  }else{ 
//    analogWrite(ENA,0);
//    digitalWrite(IN1,0);
//    digitalWrite(IN2,0);
//  }
//
//  if (moveL>0.0){
//    analogWrite(ENB,max(min(moveL*100,60),35));
//    digitalWrite(IN3,0);
//    digitalWrite(IN4,1);
//  }
//  else if (moveL<0.0){
//	  analogWrite(ENB,max(min(abs(moveL)*100,60),35));
//    digitalWrite(IN3,1);
//    digitalWrite(IN4,0);
//  }
//  else{ 
//	  analogWrite(ENB,0);
//    digitalWrite(IN3,0);
//    digitalWrite(IN4,0);    
//  }
  
}
ros::Subscriber <sensor_msgs::Joy> Motor("/joy_orig", roverCallBack);

void setup()
{
  pinMode(ENA,OUTPUT);  
  pinMode(IN1,OUTPUT); 
  pinMode(IN2,OUTPUT);
  pinMode(ENB,OUTPUT);  
  pinMode(IN3,OUTPUT); 
  pinMode(IN4,OUTPUT); 
  

  nh.initNode();
  nh.subscribe(Motor);
} 

void loop()
{
  nh.spinOnce();
  delay(10);
}
