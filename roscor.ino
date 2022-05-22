#include <ArduinoHardware.h>
#include <ros.h> 
#include <sensor_msgs/Joy.h> 
#include "Arduino.h"
#include "AX12A.h"
#include <Servo.h>

Servo servoSpin;
Servo servoGrip;

#define DirectionPin (10u)
#define BaudRate (1000000)
#define ID1 (14u)
#define ID2 (13u)
#define ID3 (12u)

#define ENA 5
#define ENB 6
#define IN1 8
#define IN2 10
#define IN3 9
#define IN4 11 
#define SPIN_SERVO 8
#define GRIP_SERVO 9

int ID1position = 512;
int ID2position = 512;
int ID3position = 512;

int statusServoSPIN = 0;
int statusServoGrip = 60;

ros::NodeHandle nh;

sensor_msgs::Joy axe_msg;
sensor_msgs::Joy button_msg;



void armPush(){
  ax12a.moveSpeed(ID1, ID1position,100);
  ++ID1position;
  delay(5);
}

void armPull(){
  ax12a.moveSpeed(ID1, ID1position,100);
  --ID1position;
  delay(5);
}

void armUp(){
  ax12a.moveSpeed(ID2, ID2position,100);
  ++ID2position;
  delay(5);
}

void armDown(){
  ax12a.moveSpeed(ID2, ID2position,100);
  --ID2position;
  delay(5);
}

void armLeft(){
  ax12a.moveSpeed(ID3, ID3position,100);
  ++ID3position;
  delay(5);
}

void armRight(){
  ax12a.moveSpeed(ID3, ID3position,100);
  --ID3position;
  delay(5);
}

void roverCallBack(const sensor_msgs::Joy& joy_orig){

	float joy1X = joy_orig.axes[1];
  float joy1Z = joy_orig.axes[0];

  float joy2X = joy_orig.axes[4];
  float joy2Z = joy_orig.axes[3];

  float backAnalogLeft = joy_orig.axes[2];
  float backAnalogRight = joy_orig.axes[5];

  byte arrowUpDown = joy_orig.axes[7];
  byte arrowLeftRight = joy_orig.axes[6];

  byte buttonX = joy_orig.buttons[2];
  byte buttonY = joy_orig.buttons[3];
  byte buttonB = joy_orig.buttons[1];
  byte buttonA = joy_orig.buttons[0];

  byte backButtonLeft = joy_orig.buttons[4];
  byte backButtonRight = joy_orig.buttons[5];

	double moveL = joy1X-(joy1Z/2);
	double moveR = joy1X+(joy1Z/2);
  
  if (moveR>0.0){
    analogWrite(ENA,max(min(moveR*100,255),10));
    digitalWrite(IN1,0);
    digitalWrite(IN2,1);
  }
  else if (moveR<0.0){
    analogWrite(ENA,max(min(abs(moveR)*100,255),10));
    digitalWrite(IN1,1);
    digitalWrite(IN2,0);
  }else{ 
    analogWrite(ENA,0);
    digitalWrite(IN1,0);
    digitalWrite(IN2,0);
  }

  if (moveL>0.0){
    analogWrite(ENB,max(min(moveL*100,255),10));
    digitalWrite(IN3,0);
    digitalWrite(IN4,1);
  }
  else if (moveL<0.0){
	  analogWrite(ENB,max(min(abs(moveL)*100,255),10));
    digitalWrite(IN3,1);
    digitalWrite(IN4,0);
  }
  else{ 
	  analogWrite(ENB,0);
    digitalWrite(IN3,0);
    digitalWrite(IN4,0);    
  }

  if(joy2Z == 1){
    armPush();
  }
  else if(joy2Z == -1){
    armPull();
  }
  else if(joy2X == 1){
    armLeft();
  }
  else if(joy2X == -1){
    armRight();
  }

  if(arrowUpDown == 1){
    armUp();
  }
  else if(arrowUpDown == -1){
    armDown();
  }

  
  if(backButtonLeft == 1){
    if(statusServoSpin == 0){
      statusServoSpin = 90;
      servoSpin.write(statusServoSpin);
    }
    else if(statusServoSpin == 90){
      statusServoSpin = 0;
      servoSpin.write(statusServoSpin);
    }
  }
  
  else(backButtonRight == 1){
    if(statusServoGrip == 60){
      statusServoSpin = 120;
      servoSpin.write(statusServoSpin);
    }
    else if(statusServoSpin == 120){
      statusServoSpin = 60;
      servoSpin.write(statusServoSpin);
    }
    delay(10);
  }
  
}
ros::Subscriber <sensor_msgs::Joy> Motor("/joy_orig", roverCallBack);

void setup()
{
  servoSpin.attach(SPIN_SERVO);
  servoGrip.attach(GRIP_SERVO);
  servoSpin.write(0);
  servoGrip.write(60);
  pinMode(ENA,OUTPUT);                
  pinMode(IN1,OUTPUT); 
  pinMode(IN2,OUTPUT);
  pinMode(ENB,OUTPUT);  
  pinMode(IN3,OUTPUT); 
  pinMode(IN4,OUTPUT); 

  ax12a.begin(BaudRate, DirectionPin, &Serial3);
  ax12a.move(ID1, ID1position, 100);
  ax12a.move(ID2, ID2position, 100);
  ax12a.move(ID3, ID3position, 100);
  delay(1000);
  

  nh.initNode();
  nh.subscribe(Motor);
} 

void loop()
{
  nh.spinOnce();
  delay(10);
}
