int a=8;
int b=7;
int c=6;
int d=5;
int e=4;
int f=3;
int g=2;
String choice;

void setup() {
  for(int i=2;i<=9;i++){
   pinMode(i,OUTPUT);
  }
  Serial.begin(9600);
}

void loop() {
  Serial.println("Press U(count up) OR D(count down)");
  while(Serial.available()==0){
  }
  choice=Serial.readString();
  if(choice=="U")
  {
    zero();
    one();
    two();
    three();
    four();
    five();
    six();
    seven();
    eight();
    nine();
  }
  if(choice=="D")
  {
     nine();
    eight();
    seven();
    six();
    five();
    four();
    three();
    two();
    one();
    zero();
  }

}
void zero() {
  digitalWrite(a,HIGH);
  digitalWrite(b,HIGH);
  digitalWrite(c,HIGH);
  digitalWrite(d,HIGH);
  digitalWrite(e,HIGH);
  digitalWrite(f,HIGH);
  digitalWrite(g,LOW);
  Serial.println("0");
  delay(1000);
}
void one(){
  digitalWrite(a,LOW);
  digitalWrite(b,HIGH);
  digitalWrite(c,HIGH);
  digitalWrite(d,LOW);
  digitalWrite(e,LOW);
  digitalWrite(f,LOW);
  digitalWrite(g,LOW);
  Serial.println("1");
  delay(1000);
  
}

void two() {
  digitalWrite(a,HIGH);
  digitalWrite(b,HIGH);
  digitalWrite(c,LOW);
  digitalWrite(d,HIGH);
  digitalWrite(e,HIGH);
  digitalWrite(f,LOW);
  digitalWrite(g,HIGH);
  Serial.println("2");
  delay(1000);
}

 void three() {
  digitalWrite(a,HIGH);
  digitalWrite(b,HIGH);
  digitalWrite(c,HIGH);
  digitalWrite(d,HIGH);
  digitalWrite(e,LOW);
  digitalWrite(f,LOW);
  digitalWrite(g,HIGH);
  Serial.println("3");
  delay(1000);
  
 }

void four() {
  digitalWrite(a,LOW);
  digitalWrite(b,HIGH);
  digitalWrite(c,HIGH);
  digitalWrite(d,LOW);
  digitalWrite(e,LOW);
  digitalWrite(f,HIGH);
  digitalWrite(g,HIGH);
  Serial.println("4");
  delay(1000);
  
}

void five() {
  digitalWrite(a,HIGH);
  digitalWrite(b,LOW);
  digitalWrite(c,HIGH);
  digitalWrite(d,HIGH);
  digitalWrite(e,LOW);
  digitalWrite(f,HIGH);
  digitalWrite(g,HIGH);
  Serial.println("5");
  delay(1000);
  
}

void six() {
  digitalWrite(a,HIGH);
  digitalWrite(b,LOW);
  digitalWrite(c,HIGH);
  digitalWrite(d,HIGH);
  digitalWrite(e,HIGH);
  digitalWrite(f,HIGH);
  digitalWrite(g,HIGH);
  Serial.println("6");
  delay(1000);
}

void seven() {
  digitalWrite(a,HIGH);
  digitalWrite(b,HIGH);
  digitalWrite(c,HIGH);
  digitalWrite(d,LOW);
  digitalWrite(e,LOW);
  digitalWrite(f,LOW);
  digitalWrite(g,LOW);
  Serial.println("7");
  delay(1000);
  }

void eight() {
  digitalWrite(a,HIGH);
  digitalWrite(b,HIGH);
  digitalWrite(c,HIGH);
  digitalWrite(d,HIGH);
  digitalWrite(e,HIGH);
  digitalWrite(f,HIGH);
  digitalWrite(g,HIGH);
  Serial.println("8");
  delay(1000);
  
}

void nine() {
  digitalWrite(a,HIGH);
  digitalWrite(b,HIGH);
  digitalWrite(c,HIGH);
  digitalWrite(d,HIGH);
  digitalWrite(e,LOW);
  digitalWrite(f,HIGH);
  digitalWrite(g,HIGH);
  Serial.println("9");
  delay(1000);
}
