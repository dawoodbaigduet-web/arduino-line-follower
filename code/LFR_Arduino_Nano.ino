// Line Following Robot - Arduino Nano + L298N + 2 IR Sensors

#define LEFT_SENSOR 2
#define RIGHT_SENSOR 3

#define ENA 5
#define IN1 8
#define IN2 9
#define ENB 6
#define IN3 10
#define IN4 11

int motorSpeed=180;

void setup(){
 pinMode(LEFT_SENSOR,INPUT);
 pinMode(RIGHT_SENSOR,INPUT);
 pinMode(ENA,OUTPUT); pinMode(IN1,OUTPUT); pinMode(IN2,OUTPUT);
 pinMode(ENB,OUTPUT); pinMode(IN3,OUTPUT); pinMode(IN4,OUTPUT);
 analogWrite(ENA,motorSpeed);
 analogWrite(ENB,motorSpeed);
}

void loop(){
 int L=digitalRead(LEFT_SENSOR);
 int R=digitalRead(RIGHT_SENSOR);

 if(L==LOW && R==LOW) forward();
 else if(L==LOW && R==HIGH) turnLeft();
 else if(L==HIGH && R==LOW) turnRight();
 else stopRobot();
}

void forward(){
 digitalWrite(IN1,HIGH); digitalWrite(IN2,LOW);
 digitalWrite(IN3,HIGH); digitalWrite(IN4,LOW);
}
void turnLeft(){
 digitalWrite(IN1,LOW); digitalWrite(IN2,LOW);
 digitalWrite(IN3,HIGH); digitalWrite(IN4,LOW);
}
void turnRight(){
 digitalWrite(IN1,HIGH); digitalWrite(IN2,LOW);
 digitalWrite(IN3,LOW); digitalWrite(IN4,LOW);
}
void stopRobot(){
 digitalWrite(IN1,LOW); digitalWrite(IN2,LOW);
 digitalWrite(IN3,LOW); digitalWrite(IN4,LOW);
}
