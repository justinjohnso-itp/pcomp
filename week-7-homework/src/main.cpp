#include <Arduino.h>

//
// Intro to Asynchronous Serial Communications
// https://itp.nyu.edu/physcomp/lab-intro-to-serial-communications/
//

// const int switchPin = 2; // digital input

// void setup() {
//    // start serial port at 9600 bps:
//    Serial.begin(9600);
//    pinMode(switchPin, INPUT);

//    // Handshake
//    while (Serial.available() <= 0) {
//      Serial.println("hello"); // send a starting message
//      delay(300);              // wait 1/3 second
//    }
// }

// Sending data in many formats (https://itp.nyu.edu/physcomp/lab-intro-to-serial-communications/#send-the-data-in-many-formats)
// void loop() {
// // read analog input, map it to make the range 0-255:
// int analogValue = analogRead(A0);
// int mappedValue = map(analogValue, 0, 1023, 0, 255);
// Serial.println(mappedValue);
 
// // print different formats:
// Serial.write(mappedValue);  // Print the raw binary value
// Serial.print('\t');             // print a tab
// // print ASCII-encoded values:
// Serial.print(mappedValue, BIN); // print ASCII-encoded binary value
// Serial.print('\t');             // print a tab
// Serial.print(mappedValue);      // print decimal value
// Serial.print('\t');             // print a tab
// Serial.print(mappedValue, HEX); // print hexadecimal value
// Serial.print('\t');             // print a tab
// Serial.print(mappedValue, OCT); // print octal value
// Serial.println();               // print linefeed and carriage return

// delay(50);
// }

// void loop() {
//    if (Serial.available()) {
//       Serial.print(analogRead(A0));
//       Serial.print(",");

//       Serial.print(analogRead(A1));
//       Serial.print(",");
   
//       Serial.println(digitalRead(switchPin));

//       delay(50);
//    }
// }

//
// Serial Input to p5.js Using the p5.webserial Library
// https://itp.nyu.edu/physcomp/labs/labs-serial-communication/lab-webserial-input-to-p5-js/
//

// Sending binary data
// void setup() {
//   Serial.begin(9600); // initialize serial communications
// }
 
// void loop() {
//   // read the input pin:
//   int potentiometer = analogRead(A0);                  
//   // remap the pot value to fit in 1 byte:
//   int mappedPot = map(potentiometer, 0, 1023, 0, 255); 
//   // print it out the serial port:
//   Serial.write(mappedPot);                             
//   // slight delay to stabilize the ADC:
//   delay(1);                                            
// }

// Sending ASCII data
// void setup() {
//    Serial.begin(9600); // initialize serial communications
// }

// void loop() {
//    int potentiometer = analogRead(A0);                  // read the input pin
//    int mappedPot = map(potentiometer, 0, 1023, 0, 255); // remap the pot value to fit in 1 byte
//    Serial.println(potentiometer);                           // print it out the serial port
//    delay(1);                                            // slight delay to stabilize the ADC
// }

//
// Serial Output From p5.js Using the p5.webserial Library
// https://itp.nyu.edu/physcomp/labs/labs-serial-communication/lab-webserial-output-from-p5-js/
//

// Binary data
// void setup() {
//   Serial.begin(9600);     // initialize serial communications
//   pinMode(5, OUTPUT);
// }
 
// void loop() {
//   if (Serial.available() > 0) { // if there's serial data available
//     int inByte = Serial.read();   // read it
//     Serial.write(inByte);         // send it back out as raw binary data
//     analogWrite(5, inByte);       // use it to set the LED brightness
//     // if you're using a speaker instead of an LED, uncomment line below  and comment out the previous line:
//     //  tone(5, inByte*10);     // play tone on pin 5
//   }
// }

// ASCII data
const int ledPin = 5; // the pin that the LED is attached to
int incomingByte;     // a variable to read incoming serial data into
 
void setup() {
  Serial.begin(9600);    // initialize serial communications
  Serial.setTimeout(10); // set the timeout for parseInt
  pinMode(5, OUTPUT);
}
 
void loop() {
  if (Serial.available() > 0) { // if there's serial data available
    int inByte = Serial.parseInt(); // read it
    if (inByte > 0) {
      Serial.write(inByte);      // send it back out as raw binary data
      analogWrite(5, inByte);    // use it to set the LED brightness
      // if you're using a speaker instead of an LED, uncomment line below  and comment out the previous line:
      //  tone(5, inByte*10);     // play tone on pin 5
    }
  }
}