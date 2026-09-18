const int btnLadder = A0, piezoPin = 8;
int notes[] = {264, 294, 330, 349};

 void setup() {
  Serial.begin(9600);
  analogReadResolution(12);
}

void loop() {
  int keyPressure = analogRead(btnLadder);

  if (keyPressure < 70) {
    noTone(piezoPin);
  } else if (keyPressure <= 100) {
    tone(piezoPin, notes[3]);
  } else if (keyPressure <= 2000) {
    tone(piezoPin, notes[2]);
  } else if (keyPressure <= 4050) {
    tone(piezoPin, notes[1]);
  } else {
    tone(piezoPin, notes[0]);
  }
  Serial.print("Pressure:");
  Serial.println(keyPressure);
  delay(100);
}
