#include <Arduino.h>

const int switchPin = 2; // digital input

void setup() {
   // start serial port at 9600 bps:
   Serial.begin(9600);
   pinMode(switchPin, INPUT);

   // Handshake
   while (Serial.available() <= 0) {
     Serial.println("hello"); // send a starting message
     delay(300);              // wait 1/3 second
   }
}

/* Sending data in many formats (https://itp.nyu.edu/physcomp/lab-intro-to-serial-communications/#send-the-data-in-many-formats)*/
/*
void loop() {
// read analog input, map it to make the range 0-255:
int analogValue = analogRead(A0);
int mappedValue = map(analogValue, 0, 1023, 0, 255);
Serial.println(mappedValue);
 
// print different formats:
Serial.write(mappedValue);  // Print the raw binary value
Serial.print('\t');             // print a tab
// print ASCII-encoded values:
Serial.print(mappedValue, BIN); // print ASCII-encoded binary value
Serial.print('\t');             // print a tab
Serial.print(mappedValue);      // print decimal value
Serial.print('\t');             // print a tab
Serial.print(mappedValue, HEX); // print hexadecimal value
Serial.print('\t');             // print a tab
Serial.print(mappedValue, OCT); // print octal value
Serial.println();               // print linefeed and carriage return

delay(50);
}
*/

void loop() {
   if (Serial.available()) {
      Serial.print(analogRead(A0));
      Serial.print(",");

      Serial.print(analogRead(A1));
      Serial.print(",");
   
      Serial.println(digitalRead(switchPin));

      delay(50);
   }
}