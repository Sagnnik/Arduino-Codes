int i,distance,pin=22,distance1;
int ldrpin=A0;
String rot;
long duration,duration1;

void setup() {
  for(i=2;i<=10;i=i+2)
  {
    pinMode(i,INPUT);
  }
  for(i=3;i<=11;i=i+2)
  {
    pinMode(i,OUTPUT);
  }
  for(i=22;i<=27;i++)
  {
    pinMode(i,OUTPUT);
  }
  pinMode(ldrpin,INPUT);
  Serial.begin(9600);
}

void loop() {
  
  int ldrstatus=analogRead(ldrpin);
  if(ldrstatus<=200)
  {
    Serial.println("Suction Motor Clockwise(C) or Anti-clockwise(A)");
    while(Serial.available()==0){}
    rot=Serial.readString();
    if(rot=="C")
    digitalWrite(26,HIGH);
    else
    digitalWrite(27,HIGH);
    digitalWrite(pin,HIGH);
    while(true){
    for(i=3;i<=11;i=i+2)
    {
      digitalWrite(i,LOW);
      delayMicroseconds(2);
    }
    for(i=3;i<=11;i=i+2)
    {
      digitalWrite(i,HIGH);
      delayMicroseconds(10);
      digitalWrite(i,LOW);
    }
    for(i=2;i<=10;i=i+2)
    {
      duration=pulseIn(i,HIGH);
      distance=duration*0.034/2;
      if(distance<=5)
      {
        duration1=pulseIn(i+2,HIGH);
        distance1=duration1*0.034/2;
        if(distance1<=7)
        {
          digitalWrite(pin+1,HIGH);
        }
        else
        {
          digitalWrite(pin,LOW);
          pin=pin+2;
          if(pin>25)
          pin=pin-3;
          digitalWrite(pin,HIGH);
        }
      }
      ldrstatus=analogRead(ldrpin);
      if(ldrstatus>200)
      break;
    }
     ldrstatus=analogRead(ldrpin);
      if(ldrstatus>200)
      break;
    }
  }

}
