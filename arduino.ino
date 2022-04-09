#define motor1Pin1 27;    // Set pin for Motor A
#define motor1Pin2 26;
#define enable1Pin 14;
#define motor2Pin1 18;    // Set pin for Motor B
#define motor2Pin2 5;
#define enable2Pin 19;
#define MOVE_FORWARD 'w'
#define MOVE_BACK 's'
#define MOVE_LEFT 'a'
#define MOVE_RIGHT 'd'

// Setting PWM properties
/*
const int freq = 500;
const int pwmChannel = 0;
const int pwmChanne2 = 1;
const int resolution = 8;
int dutyCycle = 200;
*/

void setup() {
  Serial.begin(9600);
  // sets the pins as outputs
  pinMode(motor1Pin1, OUTPUT);
  pinMode(motor1Pin2, OUTPUT);
  pinMode(enable1Pin, OUTPUT);
  pinMode(motor2Pin1, OUTPUT);
  pinMode(motor2Pin2, OUTPUT);
  pinMode(enable2Pin, OUTPUT);

  
}

void loop() {
  char byte = 0;
  Serial.readBytes(&byte, 1);
  // press w to move forward
  if (byte == MOVE_FORWARD) {
    Serial.print("move forward \n");
    moveForward();
    byte = 0;
  }
  // press s to move backward
  if (byte == MOVE_BACK) {
    moveBackward();
    Serial.print("move back \n");
    byte = 0;
  }
  // press a to turn left
  if (byte == MOVE_LEFT) {
    moveLeft();
    Serial.print("move left \n");
    byte = 0;
  }
  // press d to turn right
  if (byte == MOVE_RIGHT) {
    moveRight();
    Serial.print("move right \n");
    byte = 0;
  }
  
}

void moveForward(){
  // Move the DC motor forward at maximum speed
  Serial.println("Moving Forward");
  digitalWrite(motor1Pin1, HIGH);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, HIGH);
  delay(200);
}

void moveBackward(){
  // Move DC motor backwards at maximum speed
  Serial.println("Moving Backwards");
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, HIGH);
  digitalWrite(motor2Pin1, HIGH);
  digitalWrite(motor2Pin2, LOW);
  delay(200);
}

void moveRight(){
  // Move DC motor left at maximum speed
  Serial.println("Moving Right");
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, HIGH);
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, HIGH);
  delay(200);
}

void moveLeft(){
  // Move DC motor right at maximum speed
  Serial.println("Moving Left");
  digitalWrite(motor1Pin1, HIGH);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, HIGH);
  digitalWrite(motor2Pin2, LOW);
  delay(200);
}

void stopMotor(){
  // Stop the DC motor
  Serial.println("stop");
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, LOW);
  delay(2000);
}
