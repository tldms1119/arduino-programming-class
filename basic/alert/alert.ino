int pzo = 6;
int dly = 250;

void setup() {
  pinMode(pzo, OUTPUT);
}

void loop() {
  analogWrite(pzo, 64);
  delay(dly);
  analogWrite(pzo, 128);
  delay(dly);
  analogWrite(pzo, 255);
  delay(dly);
}
