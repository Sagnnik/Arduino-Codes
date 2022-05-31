int buttonPin = 6;
int buttonState = 0;

void effect1();
void effect2();
void effect3();
void effect4();

void setup()
{
  for(int i=9;i<=13;i++)
  {
    pinMode(i,OUTPUT);
  }
  pinMode(buttonPin,INPUT);
}

void loop()
{
  buttonState=digitalRead(buttonPin);
  if(buttonState = LOW)
  {
    effect1();
  }
}

void effect1()
{
  while(true){
  for(int i=9;i<=13;i++)
  {
    digitalWrite(i,HIGH);
  }
  delay(1000);
  for(int i=9;i<=13;i++)
  {
    digitalWrite(i,LOW);
  }
    buttonState=digitalRead(buttonPin);
    if(buttonState = HIGH)
  {
    effect2();
  } 
  }
}
void effect2()
{
  while(true)
  {
      for(int i=9;i<=13;i++)
   {
       digitalWrite(i,HIGH);
       delay(100);
       digitalWrite(i,LOW);
   }
      buttonState=digitalRead(buttonPin);
      if(buttonState = HIGH)
   {
      effect3();
   } 
  }
}
void effect3()
{
  while(true)
  {
    for(int i=13;i>=9;i--)
    {
      digitalWrite(i,HIGH);
       delay(100);
    }
    delay(1000);
    for(int i=9;i<=13;i++)
    {
      digitalWrite(i,LOW);
      delay(100);
    }
    buttonState=digitalRead(buttonPin);
      if(buttonState = HIGH)
   {
      effect4();
   } 
  }
}
void effect4()
{
  int r=0;
  while(true)
  {
    r=random(9,14);
    digitalWrite(r,HIGH);
    delay(1000);
    digitalWrite(r,LOW);
  delay(1000);
    buttonState=digitalRead(buttonPin);
      if(buttonState = HIGH)
   {
      effect1();
   } 
  }
}
