void moveForward(int speed){
  Serial.print("forward");
  ax12a.turn(12, LEFT, speed);
  ax12a.turn(5, RIGHT, speed);
  ax12a.turn(10, LEFT, speed);
  ax12a.turn(13, RIGHT, speed);
}

void moveBackward(int speed){
  Serial.print("backward");
  ax12a.turn(12, RIGHT, speed);
  ax12a.turn(5, LEFT, speed);
  ax12a.turn(10, RIGHT, speed);
  ax12a.turn(13, LEFT, speed);
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

void armPush(){
  
}

void armPull(){
  
}

void armOpen(){
  
}

void gribOpen(){
  
}

void gribClose(){
  
}

void armLeft(){
  
}

void armRight(){
  
}
