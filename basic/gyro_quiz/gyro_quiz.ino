#include <MPU6050_tockn.h>
#include <Wire.h>

MPU6050 mpu6050(Wire);

void setup() {
  Serial.begin(9600);
  Wire.begin();
  mpu6050.begin();
  // 센서의 초기값 설정
  mpu6050.calcGyroOffsets(true);
  // 센서의 특정한 초기값 설정
  // mpu6050.setGyroOffsets(x, y, z);
}

void loop() {
  mpu6050.update();
  Serial.print("angleX : ");
  Serial.print(mpu6050.getAngleX());
  Serial.print(" angleY : ");
  Serial.print(mpu6050.getAngleY());
  Serial.print(" angleZ : ");
  Serial.print(mpu6050.getAngleZ());
  Serial.println();
  delay(1000);
  if(mpu6050.getAngleX() > 45 || mpu6050.getAngleX() < -45){
    tone(8, 222, 100);
    delay(100);
    noTone(8);
  }

  if(mpu6050.getAngleY() > 45 || mpu6050.getAngleY() < -45){
    tone(8, 100, 100);
    delay(100);
    noTone(8);
  }

  if(mpu6050.getAngleZ() > 45 || mpu6050.getAngleZ() < -45){
    tone(8, 189, 100);
    delay(100);
    noTone(8);
  }
}
