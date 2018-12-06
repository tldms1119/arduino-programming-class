#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
int trig_pin = 12;
int echo_pin = 13;
int distance_btn = 7;
int light_btn = 6;

void setup() {
  pinMode(trig_pin, OUTPUT);
  pinMode(echo_pin, INPUT);
  pinMode(distance_btn, INPUT);
  pinMode(light_btn, INPUT);
  Serial.begin(9600);
  lcd.begin();
  lcd.backlight();
}

void loop() {
  Serial.println(digitalRead(distance_btn));
  Serial.println(digitalRead(light_btn));
  if(digitalRead(distance_btn) == HIGH){
    lcd.clear();
    lcd.display();
    lcd.print("distance value : ");
    lcd.setCursor(0, 1);
    lcd.print(getDistance(trig_pin, echo_pin));
  } else if(digitalRead(light_btn) == HIGH){
    int light = analogRead(A0);
    lcd.clear();
    lcd.display();
    lcd.print("light value : ");
    lcd.setCursor(0, 1);
    lcd.print(light);
  } else {
    lcd.noDisplay();
  }
  delay(500);
}

int getDistance(int aTrig_pin, int aEcho_pin){
  digitalWrite(aTrig_pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(aTrig_pin, LOW);

  long duration = pulseIn(aEcho_pin, HIGH);
  long distance = duration / 58.2;

  //Serial.println(distance);
  delay(100);

  return distance;
}
