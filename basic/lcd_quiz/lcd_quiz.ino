#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
boolean toggle = false;

void setup() {
  lcd.begin();
  lcd.backlight();
}

void loop() {
  lcd.clear();

  if(toggle == true){
    lcd.print(" (^o^)  (ToT) ");
    toggle = false;
  } else {
    lcd.print(" (ToT)  (^o^) ");
    toggle = true;
  }
  
  delay(1000);
}
