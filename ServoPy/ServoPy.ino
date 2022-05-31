#include <Servo.h>
int InBytes;

Servo servo;
int angle = 10;

void setup() {
  servo.attach(10);
  servo.write(angle);
  Serial.begin(9600);
}


void loop() 
{ 
  if (Serial.available()>0)
  {
    InBytes= Serial.read();
//    angle= InBytes.toInt();
    if(InBytes== '0')
    {
      servo.write(0);
      delay(15);
    }
    if (InBytes== '5')
    {
      servo.write(90);
      delay(15);
    }
  }
}
