#include <Servo.h>
Servo myServo;

const int potentiometerPin = A0, servoPin = 9;
int potentiometerValue, angle;

void setup() {
  Serial.begin(9600);
  myServo.attach(servoPin);
  analogReadResolution(12);
}

void loop() {
  potentiometerValue = analogRead(potentiometerPin);
  Serial.print("Potentiometer: ");
  Serial.print(potentiometerValue);

  angle = map(potentiometerValue, 0, 4095, 0, 179);
  Serial.print("\t| Angle: ");
  Serial.println(angle);

  myServo.write(angle);
  delay(15);
}