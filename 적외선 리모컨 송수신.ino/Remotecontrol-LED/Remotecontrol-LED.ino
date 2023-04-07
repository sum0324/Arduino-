#include <IRremote.h>
int RECV_PIN = 11;
IRrecv irrecv(RECV_PIN); decode_results results;

void setup() {
  Serial.begin(9600);
  Serial.println("Enabling IRin");
  irrecv.enableIRIn();
  Serial.println("Enabled IRin");

  pinMode(5, OUTPUT);
}

void loop() {
  if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX); 
    irrecv.resume(); }
  delay(100);

  if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX);
    irrecv.resume();
    if (results.value == 0xFF30CF) digitalWrite(5, HIGH);
    if (results.value == 0xFF18E7) digitalWrite(5, LOW);
  }
}

// 고유번호가 계속 달라져서 LED 안켜짐.