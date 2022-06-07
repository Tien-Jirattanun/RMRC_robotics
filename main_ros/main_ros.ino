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
=======
#define ARM_Three (9u)
#define ROTATION_ARM (17u)
#define GRIB_ARM (18u)

//ax12a variable
int baseArm = 512;
int armOne = 512;
int armTwo = 512;
int armThree = 512;
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

//---------------variable zone---------------

  double joyX = joy_orig.axes[1];
  double joyZ = joy_orig.axes[0];
  double LT = joy_orig.axes[2];
  double RT = joy_orig.axes[5];
  bool LB = joy_orig.buttons[4];
  bool RB = joy_orig.buttons[5];


//analog to digital converter

  if(LT == 1){
    LT = 0; 
  }
  else if(LT > 0){
    LT = 1;
  }
  
  if(RT == 1){
    RT = 0;
  }
  else if(RT > 0){
    RT = 1;
  }

//---------------move zone---------------

  //move forward
  if(joyX > 0 && joyZ == 0){
    speed = joyX * 100;
    moveForward(speed);
  }
  //move backward
  else if(joyX < 0 && joyZ == 0){
    speed = abs(joyX * 100);
    moveBackward(speed);
    
  }
  //turn left
  else if(joyX == 0 && joyZ > 0){
    speed = jozZ * 100;
    moveLeft(speed);
  }
  //turn right
  else if(joyX == 0 && joyZ < 0){
    speed = joyZ * 100;
    moveRight(speed);
  }

//---------------arm zone---------------

  //grib close
  if(LB == 1 && RB == 0){
    gribArmClose();
  }
  //grib open
  else if(LB == 0 && RB == 1){
    gribArmOpen();
  }

  //base left
  if(LT == 1 && RT == 0){
    baseLeft();
  }
  else (LT == 0 && RT == 1){
    baseRight();
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
