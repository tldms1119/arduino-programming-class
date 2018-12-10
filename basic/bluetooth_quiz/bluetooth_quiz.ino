#include <Servo.h>
#include <SoftwareSerial.h>

Servo myservo;
SoftwareSerial bluetooth(2, 3);

void setup() {
  myservo.attach(9);

  Serial.begin(9600);
  bluetooth.begin(9600);

  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  myservo.write(90);
}

void loop() {
  char val = bluetooth.read();

  if(bluetooth.available()){
    Serial.write(bluetooth.read());
  }

  if(val == 'a'){
    digitalWrite(7, HIGH);
  }

  if(val == 'b'){
    digitalWrite(8, HIGH);
  }

  if(val == 'c'){
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
  }

  if(val == 'l'){
    myservo.write(180);
  }

  if(val == 'r'){
    myservo.write(0);
  }
}
