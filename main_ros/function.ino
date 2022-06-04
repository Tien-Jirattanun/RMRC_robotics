void moveForward(int speed){
  Serial.print("forward");
  ax12a.turn(FL, LEFT, speed);
  ax12a.turn(FR, RIGHT, speed);
  ax12a.turn(RL, LEFT, speed);
  ax12a.turn(RR, RIGHT, speed);
}

void moveBackward(int speed){
  Serial.print("backward");
  ax12a.turn(FL, RIGHT, speed);
  ax12a.turn(FR, LEFT, speed);
  ax12a.turn(RL, RIGHT, speed);
  ax12a.turn(RR, LEFT, speed);
}

void moveRight(int speed){
  Serial.print("Right");
  ax12a.turn(FL, LEFT, speed);
  ax12a.turn(FR, LEFT, speed);
  ax12a.turn(RL, LEFT, speed);
  ax12a.turn(RR, LEFT, speed);
}

void moveLeft(int speed){
  Serial.print("Left");
  ax12a.turn(FL, RIGHT, speed);
  ax12a.turn(FR, RIGHT, speed);
  ax12a.turn(RL, RIGHT, speed);
  ax12a.turn(RR, RIGHT, speed);
  
}

void armBegin(){
  
  armOne = 840;
  armTwo = 200;
  
  ax12a.move(BASE_ARM, baseArm);
  ax12a.move(ARM_ONE, armOne);
  ax12a.move(ARM_TWO, armTwo);
  ax12a.move(ROTATION_ARM, rotationArm);
  ax12a.move(GRIB_ARM, gribArm);
  delay(20);
}

void baseLeft(){
  baseArm = baseArm + 2;
  if(baseArm > 1023){
    baseArm = 1023;
  }
  ax12a.move(BASE_ARM, baseArm);
  delay(5); 
}

void baseRight(){
  baseArm = baseArm - 2;
  if(baseArm < 0){
    baseArm = 0;
  }
  ax12a.move(BASE_ARM, baseArm);
  delay(5);
}
