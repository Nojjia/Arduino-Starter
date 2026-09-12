int switchState = 0;
void setup() {
  pinMode(2, INPUT);

  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
}

void loop() {
  switchState = digitalRead(2);

  int delay_time = 100;
  
  if (switchState == LOW) {
    /* GREEN */
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
  } else {
    /* ON PUSH */

    /* YELLOW */
    digitalWrite(3, LOW);
    digitalWrite(4, HIGH);
//  digitalWrite(5, LOW);

    delay(delay_time);

    /* RED */
//  digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, HIGH);

    delay(delay_time);

    /* GREEN */
    digitalWrite(3, HIGH);
//  digitalWrite(4, LOW);
    digitalWrite(5, LOW);

    delay(delay_time);
  }
}