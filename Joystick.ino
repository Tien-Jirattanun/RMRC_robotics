#define X_AXIS A0
#define Y_AXIS A1

int x;
int y;
int motor1;
int motor2;

void setup() {
  Serial.begin(9600);
  pinMode(X_AXIS, INPUT);  
  pinMode(Y_AXIS, INPUT);
}

void loop() {

  x = analogRead(X_AXIS);
  y = analogRead(Y_AXIS);

   
  if( x <= 520 && x >= 510 && y <= 515 && y >= 503){
    Serial.print("stop |");
    Serial.print(" x : ");
    Serial.print(x);
    Serial.print(" y : ");
    Serial.println(y);
  }
  else{
    
    if(x >= 515 && y >= 509){
      motor1 = (x-515)/2;
      motor2 = (y-509)/2;
    }
    else if(x < 515 &&  y < 509){
      motor1 = (x-515)/2;
      motor2 = (y-509)/2;
    }
    else {
      motor1 = (515-x)/2;
      motor2 = (509-y)/2;
    }
    
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

  

}
