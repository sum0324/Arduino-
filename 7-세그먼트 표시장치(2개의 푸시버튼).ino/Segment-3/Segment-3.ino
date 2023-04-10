int Pin = 2;
int Num = 0;
int i;
byte numbers[16]= {0xFC, 0x60, 0xDA, 0xF2, 0x66, 0xB6, 0xBE, 0xE4, 0xFE, 0xF6, 0xEE, 0x3E, 0x9C, 0x7A, 0x9E, 0x8E};

void displayNumbers(int n) {
      for(i = 0; i < 8; i++)
    {
      boolean state = bitRead(numbers[n], 7-i);
      digitalWrite(Pin + i, state);
    }
};

void setup() {
    pinMode(12, INPUT);
    pinMode(13, INPUT);
    for(i = 0; i < 8; i++)
    {
      pinMode(Pin + i, OUTPUT);
    }
    digitalWrite(9, HIGH);
};

void loop() {
    if(digitalRead(12) == HIGH){
      ++Num;
        if(Num > 15)
         {
         Num = 0;
         }
    }
    if(digitalRead(13) == HIGH){
      --Num;
        if(Num < 0)
         {
         Num = 15;
         }
    }
    displayNumbers(Num);
    delay(1000);
};