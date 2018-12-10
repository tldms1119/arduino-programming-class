#include <SoftwareSerial.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
SoftwareSerial bluetooth(2, 3);
int posX = 0;
int posY = 1;
int life = 3;
int lifePosX = 15;
int lifePosY = 0;

void setup() {
  Serial.begin(9600);
  bluetooth.begin(9600);
  lcd.begin();
  lcd.backlight();
  lcd.setCursor(posX, posY);
  lcd.print("(^^)");
  lcd.setCursor(lifePosX, lifePosY);
  lcd.print(life);

  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
}

void loop() {
  char val = bluetooth.read();

  if(bluetooth.available()){
    Serial.write(bluetooth.read());
  }

  if(val == 'l'){
    lcd.clear();
    posX--;
    if(posX < 0){
      posX = 12;
    }
    lcd.setCursor(posX, posY);
    lcd.print("(^^)");
  }

  if(val == 'r'){
    lcd.clear();
    posX++;
    if(posX > 12){
      posX = 0;
    }
    lcd.setCursor(posX, posY);
    lcd.print("(^^)");
  }

  if(val == 'u'){
    lcd.clear();
    posY = 0;
    lcd.setCursor(posX, posY);
    lcd.print("(^^)");
  }

  if(val == 'd'){
    lcd.clear();
    posY = 1;
    lcd.setCursor(posX, posY);
    lcd.print("(^^)");
  }

  if(val == 'g'){
    digitalWrite(8, HIGH);
    lcd.setCursor(15, posY);
    lcd.print("o");
    int i = 1;
    while(true){
      int x = 14 - i;
      if(x == posX + 4){
        break;
      }
      lcd.clear();
      lcd.setCursor(x, posY);
      lcd.print("o");
      lcd.setCursor(posX, posY);
      lcd.print("(xx)");
      i++;
      delay(500);
    }
    lcd.clear();
    lcd.setCursor(posX, posY);
    lcd.print("(^^)");
    digitalWrite(8, LOW);
    life++;
    if(life > 3){
      life = 3;
    } else {
      lcd.setCursor(lifePosX, lifePosY);
      lcd.print(life);
    }
  }

  if(val == 'w'){
    digitalWrite(9, HIGH);
  }

  if(val == 'R'){
    digitalWrite(10, HIGH);
    lcd.setCursor(15, posY);
    lcd.print("*");
    int i = 1;
    while(true){
      int x = 14 - i;
      if(x == posX + 4){
        break;
      }
      lcd.clear();
      lcd.setCursor(x, posY);
      lcd.print("*");
      lcd.setCursor(posX, posY);
      lcd.print("(^^)");
      i++;
      delay(500);
    }
    lcd.clear();
    lcd.setCursor(posX, posY);
    lcd.print("(xx)");
    digitalWrite(10, LOW);
    life--;
    if(life < 0){
      lcd.clear();
      lcd.print("Game Over");
    } else {
      lcd.setCursor(lifePosX, lifePosY);
      lcd.print(life);
    }
  }

  if(val == 'o'){
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
  }
}
