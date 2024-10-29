void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  digitalWrite(13, HIGH);
}

int startTimer = 0;
int interval = 5000;
int mode = 0;

void blink(int speed) {
  if (millis() % speed == 0) {
    if (digitalRead(13) == HIGH) {
      digitalWrite(13, LOW);
    } else {
      digitalWrite(13, HIGH);
    }
    Serial.println(millis());
    delay(50);
  }
}

void checkTimer() {
  if (millis() > startTimer + interval) {
    startTimer = millis();
    mode = !mode;
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  // Serial.println(millis());
  // blink(1000);
  checkTimer();

  if (mode == 0) blink(1000);
  if (mode == 1) blink(100);

  // switch (mode) {
  //   case 0: blink(1000);
  //   case 1: blink(100);
  // }

}
