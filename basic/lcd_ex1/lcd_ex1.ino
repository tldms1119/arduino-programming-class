#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  // initialize the LCD
  lcd.begin();

  // turn on the blacklight and print a message
  lcd.backlight();
  lcd.print("Hello, world!");
}

void loop() {
  // lcd 내용을 오른쪽으로 스크롤
  lcd.scrollDisplayRight();
  delay(500);
}
