#include <Servo.h>
Servo myServo;

int angle = 90;

void setup() {
  myServo.attach(12);
}

void loop() {
  for (angle = 0; angle <= 180; angle += 1) {
    myServo.write(angle);
    delay(15);
  }
  for (angle = 180; angle >= 0; angle -= 1) {
    myServo.write(angle);
    delay(15);
  }
}