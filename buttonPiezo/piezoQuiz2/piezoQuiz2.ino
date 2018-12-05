// preprocessor
#define C 262   // 도
#define D 294   // 레
#define E 330   // 미
#define F 349   // 파
#define G 392   // 솔
#define A 440   // 라
#define B 494   // 시
#define H 523   // 높은 도

int piezo_Pin = 8;
int tempo = 200;
int pins[] = { 2, 3 };
int notes[25] = { G,G,A,A,G,G,E,G,G,E,E,D,G,G,A,A,G,G,E,G,E,D,E,C};

void setup() {
  pinMode(piezo_Pin, OUTPUT);
  pinMode(pins[0], INPUT);
  pinMode(pins[1], INPUT);
  Serial.begin(9600);
}

void loop() {
  if(digitalRead(pins[0]) == HIGH){
    for(int i = 0; i < 12; i++) {
      Serial.println(analogRead(A0));
      tone(piezo_Pin, notes[i], analogRead(A0));
      delay(400);
     }
  }

  if(digitalRead(pins[1]) == HIGH){
   for(int i = 12; i < 25; i++) {
    Serial.println(analogRead(A0));
    tone(piezo_Pin, notes[i], analogRead(A0));
    delay(400);
    }
  }
}
