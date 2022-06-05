#include <ArduinoHardware.h>
#include <ros.h>
#include <sensor_msgs/Joy.h>
#include "Arduino.h"
#include "AX12A.h"

#define DirectionPin (10u)
#define BuadRate (1000000ul)
//wheel mode
#define FL (12u) 
#define FR (5u)
#define RL (10u)
#define RR (13u)
//servo mode
#define BASE_ARM (14u)
#define ARM_ONE  (15u)
#define ARM_TWO  (16u)
#define ARM_THREE (19u)
#define ROTATION_ARM (17u)
#define GRIB_ARM (18u)

//ax12a variable
int baseArm = 512;
int armOne = 512;
int armTwo = 512;
int armThree = 512;
int rotationArm = 512;
int gribArm = 512;

//ros setup
ros::NodeHandle nh;

sensor_msgs::Joy axe_msg;
sensor_msgs::Joy button_msg;

int speed;

void roverCallBack(const sensor_msgs::Joy& joy_orig)
{
  double x = joy_orig.axes[1];
  double z = joy_orig.axes[0];

  //move forward
  if(x > 0 && z == 0){
    speed = x * 100;
    moveForward(speed);
  }
  //move backward
  else if(x < 0 && z == 0){
    speed = abs(x * 100);
    moveBackward(speed);
    
  }
  //turn left
  else if(x == 0 && z > 0){
    speed = y * 100;
    moveLeft(speed);
  }
  //turn right
  else if(x == 0 && z < 0){
    speed = y * 100;
    moveRight(speed);
  }
}

ros::Subscriber <sensor_msgs::Joy> Motor("/joy_orig", roverCallBack);

void setup()
{
  Serial.begin(9600);
  ax12a.begin(BuadRate, DirectionPin, &Serial);
  ax12a.setEndless(FL, ON);
  ax12a.setEndless(FR, ON);
  ax12a.setEndless(RL, ON);
  ax12a.setEndless(RR, ON);

  armBegin();
  
  nh.getHardware()->setBaud(500000);
  nh.initNode();
  nh.subscribe(Motor);
} 

void loop()
{
  nh.spinOnce();
}
