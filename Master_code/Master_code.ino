String text;

void setup() {
  Serial.begin(38400);
  Serial1.begin(9600);
}

void loop() {
  while(Serial.available()==0){
  }
  text=Serial.readString();
  Serial.println(text);
  delay(200);
}
