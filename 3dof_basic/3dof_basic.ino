#include<Servo.h>
Servo servo1;
Servo servo2;
Servo servo3;

int angle=10;

void setup() {
  servo1.attach(8);
  servo2.attach(9);
  servo3.attach(11);
  servo1.write(angle);
  servo2.write(angle);
  servo3.write(angle);
  Serial.begin(9600);

}

void loop() {

  //For Servo 1
  for(angle=10; angle<90; angle++)
  {
    servo1.write(angle);
    delay(15);
  }
  for(angle=90; angle>10; angle--)
  {
    servo1.write(angle);
    delay(15);
  }
  
  // For Servo 2
  for(angle=10; angle<90; angle++)
  {
    servo2.write(angle);
    delay(15);
  }
  for(angle=90; angle>10; angle--)
  {
    servo2.write(angle);
    delay(15);
  }

  // For Servo 3
  for(angle=10; angle<90; angle++)
  {
    servo3.write(angle);
    delay(15);
  }
  for(angle=90; angle>10; angle--)
  {
    servo3.write(angle);
    delay(15);
  }

}
