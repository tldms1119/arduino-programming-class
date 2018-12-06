int a_pin = 3;
int b_pin = 7;
int c_pin = A2;
int d_pin = A4;
int e_pin = A5;
int f_pin = 4;
int g_pin = A1;
int dp_pin = A3;

int dig1 = 2;
int dig2 = 5;
int dig3 = 6;
int dig4 = A0;

byte digits[10][7] = {
  {1, 1, 1, 1, 1, 1, 0},    // 0 
  {0, 1, 1, 0, 0, 0, 0},    // 1
  {1, 1, 0, 1, 1, 0, 1},    // 2
  {1, 1, 1, 1, 0, 0, 1},    // 3
  {0, 1, 1, 0, 0, 1, 1},    // 4
  {1, 0, 1, 1, 0, 1, 1},    // 5
  {1, 0, 1, 1, 1, 1, 1},    // 6
  {1, 1, 1, 0, 0, 0, 0},    // 7
  {1, 1, 1, 1, 1, 1, 1},    // 8
  {1, 1, 1, 1, 0, 1, 1}     // 9
};

byte myName[4][7] = {
  {0, 0, 0, 1, 1, 0, 1},    // c
  {0, 0, 1, 0, 1, 1, 1},    // h
  {0, 0, 1, 1, 1, 0, 1},    // o
  {0, 1, 1, 0, 0, 0, 0}     // i
};

int digitPos[4] = {dig1, dig2, dig3, dig4};

int number = 0;
int add_btn = 8;
int sub_btn = 9;
int name_btn = 10;

void setup() {
  pinMode(dig1, OUTPUT);
  pinMode(dig2, OUTPUT);
  pinMode(dig3, OUTPUT);
  pinMode(dig4, OUTPUT);
  
  pinMode(a_pin, OUTPUT);
  pinMode(b_pin, OUTPUT);
  pinMode(c_pin, OUTPUT);
  pinMode(d_pin, OUTPUT);
  pinMode(e_pin, OUTPUT);
  pinMode(f_pin, OUTPUT);
  pinMode(g_pin, OUTPUT);
  
  pinMode(dp_pin, OUTPUT);
}

void loop() {
  if(digitalRead(add_btn) == HIGH){
    number++;
    if(number > 9){
      number = 0;
    }
    selectDigitPos(4);
    printNumber(number);
  }else if(digitalRead(sub_btn) == HIGH){
    number--;
    if(number < 0){
      number = 9;
    }
    selectDigitPos(4);
    printNumber(number);
  } else if(digitalRead(name_btn) == HIGH){
     selectDigitPos(1);
     printChar(0);
     delay(100);
     selectDigitPos(2);
     printChar(1);
     delay(100);
     selectDigitPos(3);
     printChar(2);
     delay(100);
     selectDigitPos(4);
     printChar(3);
  } else {
    clearAll();
  }
  
  delay(500);
}

void selectDigitPos(int pos){
  digitalWrite(dig1, HIGH);
  digitalWrite(dig2, HIGH);
  digitalWrite(dig3, HIGH);
  digitalWrite(dig4, HIGH);

  digitalWrite(digitPos[pos-1], LOW);
}

void printNumber(int number) {
  digitalWrite(a_pin, digits[number][0]);
  digitalWrite(b_pin, digits[number][1]);
  digitalWrite(c_pin, digits[number][2]);
  digitalWrite(d_pin, digits[number][3]);
  digitalWrite(e_pin, digits[number][4]);
  digitalWrite(f_pin, digits[number][5]);
  digitalWrite(g_pin, digits[number][6]);
}

void printChar(int number){
  digitalWrite(a_pin, myName[number][0]);
  digitalWrite(b_pin, myName[number][1]);
  digitalWrite(c_pin, myName[number][2]);
  digitalWrite(d_pin, myName[number][3]);
  digitalWrite(e_pin, myName[number][4]);
  digitalWrite(f_pin, myName[number][5]);
  digitalWrite(g_pin, myName[number][6]);
}

void clearAll() {
  digitalWrite(a_pin, LOW);
  digitalWrite(b_pin, LOW);
  digitalWrite(c_pin, LOW);
  digitalWrite(d_pin, LOW);
  digitalWrite(e_pin, LOW);
  digitalWrite(f_pin, LOW);
  digitalWrite(g_pin, LOW);
  
  digitalWrite(dp_pin, LOW);
}

void printDP() {
  digitalWrite(dp_pin, HIGH);
}
