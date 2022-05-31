int stepPin=3;
int dirPin=4;
int x=0;

void setup() {
  // put your setup code here, to run once:
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(dirPin, HIGH);
  for(x=0;x<200;x++)
  {
    digitalWrite(stepPin, HIGH);
    delay(500);
    digitalWrite(stepPin, LOW);
    delay(500);
  }
  delay(1000);
  digitalWrite(dirPin, LOW);
  for(x=0;x<400;x++)
  {
    digitalWrite(stepPin, HIGH);
    delay(500);
    digitalWrite(stepPin, LOW);
    delay(500);
  }
  delay(1000);
}
