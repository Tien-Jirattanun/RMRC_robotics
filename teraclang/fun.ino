void moveForward(int speed){
  ax12a.turn(FL, LEFT, speed);
  ax12a.turn(FR, RIGHT, speed);
  ax12a.turn(RL, LEFT, speed);
  ax12a.turn(RR, RIGHT, speed);
}

void moveBackward(int speed){
  ax12a.turn(FL, RIGHT, speed);
  ax12a.turn(FR, LEFT, speed);
  ax12a.turn(RL, RIGHT, speed);
  ax12a.turn(RR, LEFT, speed);
}

void moveRight(int speed){
  ax12a.turn(FL, LEFT, speed);
  ax12a.turn(FR, LEFT, speed);
  ax12a.turn(RL, LEFT, speed);
  ax12a.turn(RR, LEFT, speed);
}

void moveLeft(int speed){
  ax12a.turn(FL, RIGHT, speed);
  ax12a.turn(FR, RIGHT, speed);
  ax12a.turn(RL, RIGHT, speed);
  ax12a.turn(RR, RIGHT, speed);
  
}

void armBegin(){
  
  armOne = 800;
  armTwo = 200;
  armThree = 200;
  rotationArm = 512;
  
  ax12a.move(BASE_ARM, baseArm);
  ax12a.move(ARM_ONE, armOne);
  ax12a.move(ARM_TWO, armTwo);
  ax12a.move(ARM_THREE, armThree);
  ax12a.move(ROTATION_ARM, rotationArm);
  ax12a.move(GRIB_ARM, gribArm);
}

void baseLeft(){
  baseArm = baseArm + 15;
  if(baseArm > 1023){
    baseArm = 1023;
  }
  ax12a.move(BASE_ARM, baseArm); 
}

void baseRight(){
  baseArm = baseArm - 15;
  if(baseArm < 0){
    baseArm = 0;
  }
  ax12a.move(BASE_ARM, baseArm);
}

void armOneRight(){
  armOne = armOne + 15;
  if(armOne > 1023){
    armOne = 1023;
  }
  ax12a.move(ARM_ONE, armOne);
}

void armOneLeft(){
  armOne = armOne - 15;
  if(armOne < 0){
    armOne = 0;
  }
  ax12a.move(ARM_ONE, armOne);
}

void armTwoRight(){
  armTwo = armTwo + 15;
  if(armTwo > 1023){
    armTwo = 1023;
  }
  ax12a.move(ARM_TWO, armTwo);
}

void armTwoLeft(){
  armTwo = armTwo - 15;
  if(armTwo < 0){
    armTwo = 0;
  }
  ax12a.move(ARM_TWO, armTwo);

}

void armThreeRight(){
  armThree = armThree + 15;
  if(armThree > 1023){
    armThree = 1023;
  }
  ax12a.move(ARM_THREE, armThree);
}

void armThreeLeft(){
  armThree = armThree - 15;
  if(armThree < 0){
    armThree = 0;
  }
  ax12a.move(ARM_THREE, armThree);
}

void rotationArmGo(){
  rotationArm = rotationArm + 15;
  if(rotationArm > 1023){
    rotationArm = 1023;
  }
  ax12a.move(ROTATION_ARM, rotationArm);
}

void rotationArmBack(){
  rotationArm = rotationArm - 15;
  if(rotationArm < 512){
    rotationArm = 512;
  }
  ax12a.move(ROTATION_ARM, rotationArm);
}

void gribArmClose(){
  gribArm = 512;
  ax12a.move(GRIB_ARM, gribArm);
}

void gribArmOpen(){
  gribArm = 300;
  ax12a.move(GRIB_ARM, gribArm);
}
