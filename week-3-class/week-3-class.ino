#define pushButton 2
#define redLED 3
#define blueLED 4
int speed = 1000;
int lastSwitchState = LOW;

bool latch = false;

void setup() {
  // init pins
  pinMode(pushButton, INPUT);
  pinMode(redLED, OUTPUT);
  pinMode(blueLED, OUTPUT);

  // init serial
  Serial.begin(9600);
}

void blinkLED(int whichPin, int howLong) {
  digitalWrite(whichPin, HIGH);
  delay(howLong);
  digitalWrite(whichPin, LOW);
  delay(howLong);
}

void loop() {
  int switchState = digitalRead(pushButton);
  Serial.println(switchState);

  // if (switchState == HIGH && lastSwitchState == LOW) {
  //   blinkLED(blueLED, 1000);
  // }

  if (switchState == HIGH && lastSwitchState == LOW) {
    latch = !latch;
    digitalWrite(blueLED, latch);
    digitalWrite(redLED, !latch);
    delay(10); // debounce
  }

  lastSwitchState = switchState;
}