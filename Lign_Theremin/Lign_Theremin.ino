const int sensorPin = A0, piezoPin = 8, ledPin = LED_BUILTIN;
int sensorValue, sensorLow = 4095, sensorHigh = 0;
int pitch;

void setup() {
  Serial.begin(9600);
  analogReadResolution(12);
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, HIGH);

  while (millis() < 5000) {
    sensorValue = analogRead(sensorPin);

    digitalWrite(ledPin, HIGH);
    if (sensorValue > sensorHigh) {
      sensorHigh = sensorValue;
    }
    if (sensorValue < sensorLow) {
      sensorLow = sensorValue;
    }
    digitalWrite(ledPin, LOW);
  }
}

void loop() {
  sensorValue = analogRead(sensorPin);
  pitch = map(sensorValue, sensorLow, sensorHigh, 50, 4000);

  Serial.print("Sensor: ");
  Serial.print(sensorValue);

  Serial.print("\tPitch: ");
  Serial.println(pitch);

  tone(piezoPin, pitch,20);

  delay(10);
}
