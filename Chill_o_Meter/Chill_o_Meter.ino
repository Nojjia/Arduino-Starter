const int sensorPin = A0;
const float baselineTemp = 20.0;

void setup() {
  Serial.begin(9600);
  for (int pin_no = 2; pin_no < 5; pin_no++) {
    pinMode(pin_no, OUTPUT);
    digitalWrite(pin_no, LOW);
  }
}

void loop() {
  int sensorVal = analogRead(sensorPin);
  float voltage = (sensorVal * 5.0) / 1024.0;
  float temperature = (voltage - 0.6) * 100;

  Serial.print("| Sensor Value: ");
  Serial.print(sensorVal);

  Serial.print("\t| Volt: ");
  Serial.print(voltage);

  Serial.print("\t| Degrees C: ");
  Serial.print(temperature);

  Serial.println("\t|");

  if (temperature < (baselineTemp + 2)) {
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  } else if (temperature >= (baselineTemp + 2) && temperature < (baselineTemp + 4 )) {
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  } else if (temperature >= (baselineTemp + 4) && temperature < (baselineTemp + 6 )) {
    digitalWrite(2, LOW);
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
  } else if (temperature >= (baselineTemp + 6 )) {
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, HIGH);
  }
  delay(1);
}
