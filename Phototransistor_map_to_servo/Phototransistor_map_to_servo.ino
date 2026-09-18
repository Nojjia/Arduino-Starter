#include <Servo.h>

Servo myServo;

const int phototransistorPin = A0, servoPin = 9;
int phototransistorValue, angle;

void setup() {
  Serial.begin(9600);
  analogReadResolution(12);
  myServo.attach(servoPin);
}

void loop() {
  phototransistorValue = analogRead(phototransistorPin);
  angle = map(phototransistorValue, 0, 4095, 0, 179);

  Serial.print("Phototransistor: ");
  Serial.print(phototransistorValue);

  Serial.print("\t| Angle: ");
  Serial.println(angle);

  myServo.write(angle);
  delay(5);
}
