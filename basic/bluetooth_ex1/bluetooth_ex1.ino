#include <SoftwareSerial.h> // 시리얼통신 라이브러리 호출

int blueTx = 2;
int blueRx = 3;
SoftwareSerial mySerial(blueTx, blueRx);

void setup() {
  Serial.begin(9600);
  mySerial.begin(9600);
}

void loop() {
  if(mySerial.available()){
    // 블루투스 측 내용을 시리얼 모니터에 출력
    Serial.write(mySerial.read());
  }

  if(Serial.available()){
    // 시리얼 모니터 내용을 블루투스 측에 write
    mySerial.write(Serial.read());
  }
}
