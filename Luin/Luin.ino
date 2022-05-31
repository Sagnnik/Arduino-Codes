

void setup() {
  pinMode(6,OUTPUT);
   pinMode(A0,INPUT);
   Serial.begin(9600);
}

void loop() {
  int ldrValue=analogRead(A0);
  float x=ldrValue/102.3;
  int n=x;
  analogWrite(6,ldrValue/4);
}
