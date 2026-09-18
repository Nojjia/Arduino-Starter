#include "Arduino_LED_Matrix.h"

ArduinoLEDMatrix matrix;

/* Define Sensor and Actuator */
const short sensor = 8;
short actuator = 2;

/* Define current and previous states */
short stateCurrent = 0, statePrevious = 0;

unsigned long timeCurrent = 0, timePrevious = 0;

/* Define time interval for count down */
long interval = 1000;

/* Define matrix LED frame */
byte frame[8][12] = {
	{ 0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,1,1,1,1,0,0,1,1,1,1,0 },
	{ 0,1,0,0,1,0,0,1,0,0,1,0 },
	{ 0,1,1,1,1,0,0,1,1,1,1,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,1,0,0,0,0,0,0,1,0,0 },
	{ 0,0,1,1,1,1,1,1,1,1,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0 }
};


void setup() {
  Serial.begin(9600);

  for (int ledPin = 2; ledPin < 8; ++ledPin) {
    pinMode(ledPin, OUTPUT);
  }
  pinMode(sensor, INPUT);

  matrix.begin();
}

void loop() {
  /* Get time elapsed since arduino r4 first ran loop */
  timeCurrent = millis();

  if ((timeCurrent - timePrevious) > interval) {
    timePrevious = timeCurrent;
    digitalWrite(actuator, HIGH);
    ++actuator;
    Serial.print("Time: ");
    Serial.println(timeCurrent);
    if (actuator == 7) matrix.renderBitmap(frame, 8, 12);
  }

  stateCurrent = digitalRead(sensor);

  if (stateCurrent != statePrevious) {
    for (int i = 2; i < 8; ++i) {
      digitalWrite(i, LOW);
    }

    actuator = 2;
    timePrevious = timeCurrent;
  }

  statePrevious = stateCurrent;
}
