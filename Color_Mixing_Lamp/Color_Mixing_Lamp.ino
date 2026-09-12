const int redSensorPin = A0, greenSensorPin = A1, blueSensorPin = A2;
const int redLEDPin = 11, greenLEDPin = 9, blueLEDPin = 10;

int redSensorValue = 0, blueSensorValue = 0, greenSensorValue = 0;
int redValue = 0, greenValue = 0, blueValue = 0;

void setup() {
  Serial.begin(9600);

  pinMode(redLEDPin, INPUT);
  pinMode(greenLEDPin, INPUT);
  pinMode(blueLEDPin, INPUT);
}

void loop() {
  redSensorValue = analogRead(redSensorPin);
  delay(5);
  greenSensorValue = analogRead(greenSensorPin);
  delay(5);
  blueSensorValue = analogRead(blueSensorPin);

  redValue = redSensorValue / 4;
  greenValue = greenSensorValue / 4;
  blueValue = blueSensorValue / 4;

  Serial.print("Sensor value | Red: ");
  Serial.print(redSensorValue);
  Serial.print("\t| Green: ");
  Serial.print(greenSensorValue);
  Serial.print("\t| Blue: ");
  Serial.println(blueSensorValue);

  Serial.print("RGB value    | Red: ");
  Serial.print(redValue);
  Serial.print("\t| Green: ");
  Serial.print(greenValue);
  Serial.print("\t| Blue: ");
  Serial.println(blueValue);
  Serial.println();

  analogWrite(redLEDPin, redValue);
  analogWrite(greenLEDPin, greenValue);
  analogWrite(blueLEDPin, blueValue);
}
