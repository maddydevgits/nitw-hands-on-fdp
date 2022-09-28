#include "ESP32Servo.h"

Servo myservo;

void setup() {
  // put your setup code here, to run once:
  myservo.attach(22);
  myservo.write(0);

}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i=0;i<90;i++) {
    myservo.write(i);
    delay(10);
  }
  for(int i=90;i>0;i--) {
    myservo.write(i);
    delay(10);
  }
}
