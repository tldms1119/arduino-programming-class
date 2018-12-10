#include <SoftwareSerial.h>

// 아두이노와 블루투스의 rx, tx가 서로 교차되게끔!
SoftwareSerial bluetooth(2, 3);

void setup() {
  Serial.begin(9600);
  bluetooth.begin(9600);

  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
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
}
