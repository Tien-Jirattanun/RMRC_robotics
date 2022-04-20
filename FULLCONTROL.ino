#define X_AXIS A0
#define Y_AXIS A1

#define motor1Pin1 2     // Set pin for Motor A
#define motor1Pin2 3 
#define motor2Pin1 4     // Set pin for Motor B
#define motor2Pin2 5

//Enable pins for PWM
#define enablePin1 6
#define enablePin2 9

int PWM_speed = 255;

int x;
int y;
int motor1;
int motor2;

void setup() {
  Serial.begin(9600);
  //motor
  pinMode(motor1Pin1, OUTPUT);
  pinMode(motor1Pin2, OUTPUT);
  pinMode(motor2Pin1, OUTPUT);
  pinMode(motor2Pin2, OUTPUT);
  //pwm
  pinMode(enablePin1, OUTPUT);
  pinMode(enablePin2, OUTPUT);
  //joystick
  pinMode(X_AXIS, INPUT);  
  pinMode(Y_AXIS, INPUT);

}

void loop(){
  //joy Read
  x = analogRead(X_AXIS);
  y = analogRead(Y_AXIS);

    if(x >= 515 && y >= 509){
      motor1 = (x-515)/2;
      motor2 = (y-509)/2;
      if(motor1 > 255){
        motor1 = 255;
      }
      else if(motor1 < -255){
        motor1 = -255;
      }
      if(motor2 > 255){
        motor2 = 255;
      }
      else if(motor2 < -255){
        motor2 = -255;
      }
    }
    else if(x < 515 &&  y < 509){
      motor1 = (x-515)/2;
      motor2 = (y-509)/2;
      if(motor1 > 255){
        motor1 = 255;
      }
      else if(motor1 < -255){
        motor1 = -255;
      }
      if(motor2 > 255){
        motor2 = 255;
      }
      else if(motor2 < -255){
        motor2 = -255;
      }
    }
    else {
      motor1 = (515-x)/2;
      motor2 = (509-y)/2;
      if(motor1 > 255){
        motor1 = 255;
      }
      else if(motor1 < -255){
        motor1 = -255;
      }
      if(motor2 > 255){
        motor2 = 255;
      }
      else if(motor2 < -255){
        motor2 = -255;
      }
    }
    
    

  //motor
  if( x <= 520 && x >= 510 && y <= 515 && y >= 503){
    motorStop();
    Serial.print("stop |");
    Serial.print(" x : ");
    Serial.print(x);
    Serial.print(" y : ");
    Serial.println(y);
  }
  else if(motor1 >= 0 && motor2 >= 0){
    info(motor1, motor2, x, y);
    moveForward(motor1 ,motor2);
  }
  else if(motor1 < 0 && motor2 < 0){
    info(motor1, motor2, x, y);
    motor1 = motor1 * -1;
    motor2 = motor2 * -1;
    moveBackward(motor1 ,motor2);
  }
  else if(motor1 >= 0 && motor2 < 0){
    info(motor1, motor2, x, y);
    motor2 = motor2 * -1;
    moveLeft(motor1 ,motor2);
  }
  else if(motor1 < 0 && motor2 >= 0){
    info(motor1, motor2, x, y);
    motor1 = motor1 * -1;
    moveRight(motor1 ,motor2);
  }
  else{
    info(motor1, motor2, x, y);
    motorStop();
  }
}

void info(int motor1, int motor2, int x, int y){
  Serial.print(" motor1 : ");
  Serial.print(motor1);
  Serial.print(" motor2 : ");
  Serial.print(motor2);
  Serial.print("||");
  Serial.print(" x : ");
  Serial.print(x);
  Serial.print(" y : ");
  Serial.println(y);
}

void moveForward(int speed1 ,int speed2){
  
  analogWrite(enablePin1, speed1);
  analogWrite(enablePin2, speed2); 

  digitalWrite(motor1Pin1, HIGH);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, HIGH);
  digitalWrite(motor2Pin2, LOW);
}

void moveRight(int speed1 ,int speed2){
  
  analogWrite(enablePin1, speed1);
  analogWrite(enablePin2, speed2);

  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, HIGH);
  digitalWrite(motor2Pin1, HIGH);
  digitalWrite(motor2Pin2, LOW);
}

void moveLeft(int speed1 ,int speed2){
  
  analogWrite(enablePin1, speed1);
  analogWrite(enablePin2, speed2);

  digitalWrite(motor1Pin1, HIGH);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, HIGH);
}

void moveBackward(int speed1 ,int speed2){
  
  analogWrite(enablePin1, speed1);
  analogWrite(enablePin2, speed2);

  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, HIGH);
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, HIGH);
}

void motorStop(){
  
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, LOW);
}

void motorBreak(){
  
  digitalWrite(motor1Pin1, HIGH);
  digitalWrite(motor1Pin2, HIGH);
  digitalWrite(motor2Pin1, HIGH);
  digitalWrite(motor2Pin2, HIGH);
}
