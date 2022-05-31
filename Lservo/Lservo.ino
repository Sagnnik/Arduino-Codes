#include<Servo.h>
Servo myservo;

void setup() {
  
  myservo.attach(9);
  pinMode(A0,INPUT);
}

void loop() {
  int val=analogRead(A0);
  val=map(val,0,1023,0,180);
  myservo.write(val);
}
