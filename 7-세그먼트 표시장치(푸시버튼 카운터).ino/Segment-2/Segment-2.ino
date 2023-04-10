int num = 0;

byte numbers[16][8]= {
  {1,1,1,1,1,1,0,0},
  {0,1,1,0,0,0,0,0},
  {1,1,0,1,1,0,1,0},
  {1,1,1,1,0,0,1,0},
  {0,1,1,0,0,1,1,0},
  {1,0,1,1,0,1,1,0},
  {1,0,1,1,1,1,1,0},
  {1,1,1,0,0,1,0,0},
  {1,1,1,1,1,1,1,0},
  {1,1,1,1,0,1,1,0},
  {1,1,1,0,1,1,1,0},
  {0,0,1,1,1,1,1,0},
  {1,0,0,1,1,1,0,0},
  {0,1,1,1,1,0,1,0},
  {1,0,0,1,1,1,1,0},
  {1,0,0,0,1,1,1,0}
};

void displayNumbers(int n){
  int pin = 2;
  for(int i = 0; i < 8; i++) {
    digitalWrite(pin+i, numbers[n][i]);
    }
}

void setup() {
  pinMode(12, INPUT);
  for (int i = 2; i <= 9; i++) {
    pinMode(i, OUTPUT);
    }
    digitalWrite(9, HIGH);
}

void loop() {
  if (digitalRead(12) == HIGH){
    ++num;
    if (num > 9) {
      num = 0;
      }
    }
    displayNumbers(num);
    delay(300);
}