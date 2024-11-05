#include <Arduino.h>
#include <Servo.h>

Servo myServo;

//
// P5 to Arduino
//

// void setup() {
//   Serial.begin(9600);
//   myServo.attach(11);
// }
// void loop() {
//   if(Serial.available()){
//   byte byteFromSerial = Serial.read();
//   int mappedValue = map(byteFromSerial,0,100,0,170);
//   analogWrite(3,mappedValue);
//   myServo.write(mappedValue);
//   }
// }

//
// Multiple values with parseInt()
//
// void setup() {
//   Serial.begin(9600);
//   myServo.attach(11);
// }
// void loop() {
//   if (Serial.available()) {
    
//     // read first part of string as int
//     int fromSerial = Serial.parseInt();
//     analogWrite(3, fromSerial);
    
//     // read second part of string as int
//     fromSerial = Serial.parseInt();
//     analogWrite(5, fromSerial);   
//   }
// }

//
// Multiple ASCII values, Arduino to P5
//
void setup() {
  Serial.begin(9600);
}
void loop() {
  int valueToSend = analogRead(A0);
  Serial.print(valueToSend);
  Serial.print(",");
  valueToSend = analogRead(A1);
  Serial.println(valueToSend);
  delay (50);
}