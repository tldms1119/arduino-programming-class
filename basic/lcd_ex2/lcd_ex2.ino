#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  Serial.begin(9600);
  
  lcd.begin();
  lcd.backlight();
}

void loop() {
  int light = analogRead(A0);
  Serial.println(light);

  lcd.clear();
  lcd.print("light value : ");
  lcd.setCursor(0, 1);
  lcd.print(light);

  int ledLight = map(light, 120, 1023, 0, 255);
  analogWrite(3, ledLight);
  
  delay(1000);
}
