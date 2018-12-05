int trig_pin = 12;
int echo_pin = 13;
int led_red = 3;
int led_green = 2;
int button = 8;

void setup() {
  Serial.begin(9600);
  pinMode(led_red, OUTPUT);
  pinMode(led_green, OUTPUT);
  pinMode(trig_pin, OUTPUT);
  pinMode(echo_pin, INPUT);
  pinMode(button, INPUT);
}

void loop() {
  digitalWrite(trig_pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig_pin, LOW);
  long duration = pulseIn(echo_pin, HIGH);
  long distance = duration / 58.2;
  Serial.println(distance);
  
  if(digitalRead(button) == HIGH && distance >= 5 && distance < 10){
    digitalWrite(led_red, LOW);
    digitalWrite(led_green, HIGH);
  } else if(digitalRead(button) == HIGH) {
    digitalWrite(led_green, LOW);
    digitalWrite(led_red, HIGH);
  } else {
    digitalWrite(led_green, LOW);
    digitalWrite(led_red, LOW);
  }

  delay(400);
}
