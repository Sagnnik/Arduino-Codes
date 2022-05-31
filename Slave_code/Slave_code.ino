String text;

void setup() {
  Serial.begin(9600);
}

void loop() {
  if(Serial.available()>0)
  {
    text=Serial.read();
  }
  Serial.println(text);
}
