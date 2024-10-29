int lastSensorState = LOW; // previous state
int threshold = 250; // threshold value

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); // init serial connection
}

void loop() {
  // put your main code here, to run repeatedly:
  // read the button
  int sensorState = analogRead(A0);

  // if above threshold
  if (sensorState >= threshold) {
    // check that previous val was below the threshold (no repeating of the message)
    if (lastSensorState < threshold) {
      Serial.println("Sensor crossed the threshold");
    }
  }

  // save sensor state
  lastSensorState = sensorState;
  // Serial.println(sensorState);
}
