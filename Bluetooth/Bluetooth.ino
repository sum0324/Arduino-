#include <SoftwareSerial.h>

#define CDS A0
#define RX 4
#define TX 5
SoftwareSerial BT(TX, RX);


void setup() {
  Serial.begin(9600);
  BT.begin(9600);
}


void loop() {
  int light = map(analogRead(CDS), 0, 1023, 0, 255);
  BT.printhln(light);

  delay(3000);
}