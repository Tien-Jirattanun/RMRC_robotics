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
  armThree = 0;
  
  ax12a.move(BASE_ARM, baseArm);
  ax12a.move(ARM_ONE, armOne);
  ax12a.move(ARM_TWO, armTwo);
  ax12a.move(ARM_THREE, armThree);
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

void armOneRight(){
  armOne = armOne + 2;
  if(armOne > 1023){
    armOne = 1023;
  }
  ax12a.move(ARM_ONE, armOne);
  delay(5);
}

void armOneLeft(){
  armOne = armOne - 2;
  if(armOne < 0){
    armOne = 0;
  }
  ax12a.move(ARM_ONE, armOne);
  delay(5);
}

void armTwoRight(){
  armTwo = armTwo + 2;
  if(armTwo > 1023){
    armTwo = 1023;
  }
  ax12a.move(ARM_TWO, armTwo);
  delay(5);
}

void armTwoLeft(){
  armTwo = armTwo - 2;
  if(armTwo < 0){
    armTwo = 0;
  }
  ax12a.move(ARM_TWO, armTwo);
  delay(5);
}

void armThreeRight(){
  armThree = armThree + 2;
  if(armThree > 1023){
    armThree = 1023;
  }
  ax12a.move(ARM_THREE, armThree);
  delay(5);
}

void armThreeLeft(){
  armThree = armThree - 2;
  if(armThree < 0){
    armThree = 0;
  }
  ax12a.move(ARM_THREE, armThree);
  delay(5);
}

void rotationArmGo(){
  rotationArm = 1023;
  ax12a.move(ROTATION_ARM, rotationArm);
  delay(5);
}

void rotationArmBack(){
  rotationArm = 512;
  ax12a.move(ROTATION_ARM, rotationArm);
  delay(5);
}

void gribArmClose(){
  gribArm = 512;
  ax12a.move(GRIB_ARM, gribArm);
  delay(5);
}

void gribArmOpen(){
  gribArm = 1023;
  ax12a.move(GRIB_ARM, gribArm);
  delay(5);
}
