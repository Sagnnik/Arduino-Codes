#include<Wire.h>
#include<LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x20,16,2);

void setup() {
  lcd.begin(16,2);
  lcd.backlight();
  lcd.print("Hello World");
  lcd.setCursor(0,1);
  lcd.print("Proteus I2C");
}

void loop() {
 

}
