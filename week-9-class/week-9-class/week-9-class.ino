//////////////////////////////////////
// SERIAL COMMUNICATION
// void setup() {
//   Serial.begin(9600);
//   // analogWrite(2, 255); 
// }

// void loop() {
//   // int timeNow = millis()/1000;
//   // Serial.println(timeNow);
//   // delay(1000);

//   if (Serial.available() > 0) {
//     int fromSerial = Serial.parseInt();
//     Serial.println(fromSerial);
//     analogWrite(2, fromSerial);  // PWM pin, dim LED to this value (up to 255)
//     delay(500);
//   }
// }
//////////////////////////////////////

// P5 to Arduino (binary)
void setup() {
  Serial.begin(9600);
}
void loop() {
  if(Serial.available()){
  byte byteFromSerial = Serial.read();
  analogWrite(3,byteFromSerial);
  }
}

// P5 to Arduino (ascii)
// void setup() {
//   Serial.begin(9600);
// }
// void loop() {
//   if (Serial.available()) {
//     int intFromSerial = Serial.parseInt();
//     analogWrite(3, intFromSerial);
//   }
// }

// Arduino to P5 (binary)
// void setup() {
//   Serial.begin(9600);
// }
// void loop() {
//   int analogValue = analogRead(A0);
//   byte byteToSend = map (analogValue, 0, 1023, 0, 255);
//   Serial.write(byteToSend);
//   delay(50);
// }

// Arduino to P5 (ascii)
// void setup() {
//   Serial.begin(9600);
// }
// void loop() {
//   int analogValue = analogRead(A0);
//   Serial.println(analogValue);
//   delay(50);
// }