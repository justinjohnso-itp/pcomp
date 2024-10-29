#include <Servo.h>

Servo myServo;

void setup() {
  Serial.begin(9600);
  // pinMode(11, OUTPUT);
  // analogWrite(11, 1000);

  myServo.attach(11);
}

void loop() {
  int potValue = constrain(analogRead(A0), 15, 1010);
  Serial.println(potValue);
  int mappedValue = map(potValue, 15, 1010, 10, 170);

  myServo.write(mappedValue);
  delay(50);

  // tone(11, mappedValue, 100);
  // delay(100);

  // digitalWrite(3, HIGH);
  // delayMicroseconds(potValue); // debounce
  // digitalWrite(3, LOW);
  // delayMicroseconds(1023 - potValue); // debounce

  // if (potValue > 500) {
  //   digitalWrite(3, HIGH);
  // } else {
  //   digitalWrite(3, LOW);
  // }
}
