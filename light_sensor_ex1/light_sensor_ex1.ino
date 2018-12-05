void setup() {
}

void loop() {
  int light = analogRead(A0);
  // 어두울수록 led 조명 밝게
  int ledLight = map(light, 0, 1023, 0, 255);
  analogWrite(9, ledLight);
}
