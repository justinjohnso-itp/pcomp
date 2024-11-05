#include <Arduino.h>
#include <Servo.h>

Servo myServo;

void setup() {
  Serial.begin(9600);
  myServo.attach(11);
}
void loop() {
  if(Serial.available()){
  byte byteFromSerial = Serial.read();
  int mappedValue = map(byteFromSerial,0,100,0,170);
  analogWrite(3,mappedValue);
  myServo.write(mappedValue);
  }
}