#include<LiquidCrystal.h>
LiquidCrystal lcd(12,11,10,9,8,7);
String s;

void setup() {
  Serial.begin(9600);
  lcd.begin(16,2);
  Serial.println("Enter the text to print on lcd");
  while(Serial.available()==0){
  }
  s=Serial.readString();
}

void loop() {
  lcd.setCursor(0,0); 
  lcd.print(s);
  delay(200);
  lcd.clear();
}
