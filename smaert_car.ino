//motor pins
#define ENA 10
#define IN_ONE 9
#define IN_TWO 8
#define ENB 5
#define IN_THREE 7
#define IN_FOUR 6

//Sensor pins
#define LEFT_SENSOR A0
#define MID_SENSOR A1
#define RIGHT_SENSOR A2

void forward(int spd){
  //Motor 1 
  digitalWrite(IN_TWO, HIGH);
  digitalWrite(IN_ONE, LOW);
  //Motor 2
  digitalWrite(IN_FOUR, HIGH);
  digitalWrite(IN_THREE, LOW);
  //start moving motors
  analogWrite(ENA,spd);
  analogWrite(ENB,spd);
  }

void turn_right(int spd){
  //Motor 1 
  digitalWrite(IN_TWO, HIGH);
  digitalWrite(IN_ONE, LOW);
  //Motor 2
  digitalWrite(IN_FOUR, LOW);
  digitalWrite(IN_THREE, HIGH);
  //start moving motors
  analogWrite(ENA,spd);
  analogWrite(ENB,spd);
  }
void turn_left(int spd){
  //Motor 1 
  digitalWrite(IN_TWO, LOW);
  digitalWrite(IN_ONE, HIGH);
  //Motor 2
  digitalWrite(IN_FOUR, HIGH);
  digitalWrite(IN_THREE, LOW);
  //start moving motors
  analogWrite(ENA,spd);
  analogWrite(ENB,spd);
  }
void stopAll(){
  //Motor 1 
  digitalWrite(IN_TWO, LOW);
  digitalWrite(IN_ONE, LOW);
  //Motor 2
  digitalWrite(IN_FOUR, LOW);
  digitalWrite(IN_THREE, LOW);
  //start moving motors
  analogWrite(ENA,0);
  analogWrite(ENB,0);
  }
  void reverse(int spd){
    //Motor 1 
  digitalWrite(IN_TWO, LOW);
  digitalWrite(IN_ONE, HIGH);
  //Motor 2
  digitalWrite(IN_FOUR, LOW);
  digitalWrite(IN_THREE, HIGH);
  //start moving motors
  analogWrite(ENA,spd);
  analogWrite(ENB,spd);
    }
void setup() {
  // put your setup code here, to run once:
  //  setting up L298N motor driver board
  pinMode(ENA,OUTPUT);
  pinMode(ENB,OUTPUT);
  pinMode(IN_ONE,OUTPUT);
  pinMode(IN_TWO,OUTPUT);
  pinMode(IN_THREE,OUTPUT);
  pinMode(IN_FOUR,OUTPUT);

  Serial.begin(9600);
  delay(2000);
}

void loop() {
  
  int spd = 80;
  // put your main code here, to run repeatedly:
//  if the pins reads a low voltage it detects a black line

//Serial.print("left: ");
//Serial.print(analogRead(LEFT_SENSOR));
//Serial.print('\n');
//Serial.print("mid: ");
//Serial.print(analogRead(MID_SENSOR));
//Serial.print('\n');
//Serial.print("right: ");
//Serial.print(analogRead(RIGHT_SENSOR));
//Serial.print('\n');
//Serial.print('\n');

//delay(3000);
  if(analogRead(LEFT_SENSOR) > 200 && analogRead(MID_SENSOR) > 200 && analogRead(RIGHT_SENSOR) > 200){
    Serial.print("Forward\n");
    forward(spd);
//    delay(2000);
    }
  if(analogRead(LEFT_SENSOR) > 200 && analogRead(MID_SENSOR) > 200 && analogRead(RIGHT_SENSOR) < 200){
    Serial.print("turn right\n");
    turn_left(spd);
//    delay(2000);
    }
  if(analogRead(LEFT_SENSOR) < 200 && analogRead(MID_SENSOR) > 200 && analogRead(RIGHT_SENSOR) > 200){
    Serial.print("Turn Left\n");
    turn_right(spd);
//    delay(2000);
    }
    if(analogRead(LEFT_SENSOR) < 200 && analogRead(MID_SENSOR) < 200 && analogRead(RIGHT_SENSOR) < 200){
    Serial.print("stop\n");
    stopAll();
//    delay(2000);
    }
    if((analogRead(LEFT_SENSOR) > 200 && analogRead(MID_SENSOR) < 200 && analogRead(RIGHT_SENSOR) < 200)||
    (analogRead(LEFT_SENSOR) < 200 && analogRead(MID_SENSOR) < 200 && analogRead(RIGHT_SENSOR) > 200)){
      Serial.print("Reverse\n");
      reverse(spd);
      }
}
