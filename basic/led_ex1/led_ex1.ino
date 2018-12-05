void setup() {
  pinMode(8, OUTPUT);
  pinMode(13, INPUT);
}

void loop() {
  int value = digitalRead(13);

  if(value == HIGH){
    digitalWrite(8, HIGH);
  } else {
    digitalWrite(8, LOW);
  }
}
