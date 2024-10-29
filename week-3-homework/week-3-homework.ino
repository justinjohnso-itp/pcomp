int audioPin = 8;

void setup() {}

void loop() {
  // play tone for 1 second
  tone(audioPin, 440, 1000);
  // wait 1 second
  delay(1000);
}
