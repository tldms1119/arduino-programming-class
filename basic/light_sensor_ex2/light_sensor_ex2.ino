void setup() {
}

void loop() {
  int light = analogRead(A0);
  int hertz = map(light, 0, 1023, 31, 4978);
  tone(8, hertz, 400);
  delay(400);
  noTone(8);
}
