#define Motorpin1_1 19
#define Motorpin1_2 18
#define Motorpin2_1 27
#define Motorpin2_2 13


void setup() {
  Serial.begin(9600);
  pinMode(Motorpin1_1, OUTPUT);
  pinMode(Motorpin1_2, OUTPUT);
  pinMode(Motorpin2_1, OUTPUT);
  pinMode(Motorpin2_2, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  /*MoveForwards();
  delay(2000);
  MoveBackwards();
  delay(2000);
  TurnRight();
  delay(2000);
  TurnLeft();
  delay(2000);*/
  Stop();
}
void MoveForwards() {
  digitalWrite(Motorpin1_1, HIGH);
  digitalWrite(Motorpin1_2, LOW);
  digitalWrite(Motorpin2_1, HIGH);
  digitalWrite(Motorpin2_2, LOW);
}
void MoveBackwards(){
  digitalWrite(Motorpin1_1, LOW);
  digitalWrite(Motorpin1_2, HIGH);
  digitalWrite(Motorpin2_1, LOW);
  digitalWrite(Motorpin2_2, HIGH);
}
void TurnRight() {
  digitalWrite(Motorpin1_1, HIGH);
  digitalWrite(Motorpin1_2, LOW);
  digitalWrite(Motorpin2_1, LOW);
  digitalWrite(Motorpin2_2, HIGH);
}
void TurnLeft() {
  digitalWrite(Motorpin1_1, LOW);
  digitalWrite(Motorpin1_2, HIGH);
  digitalWrite(Motorpin2_1, HIGH);
  digitalWrite(Motorpin2_2, LOW);
}
void Stop() {
  digitalWrite(Motorpin1_1, LOW);
  digitalWrite(Motorpin1_2, LOW);
  digitalWrite(Motorpin2_1, LOW);
  digitalWrite(Motorpin2_2, LOW);
}

