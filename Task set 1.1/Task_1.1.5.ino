void setup() {
  pinMode(3, INPUT);
  pinMode(13, OUTPUT);
}

void loop() {
  if (digitalRead(3) == HIGH) {
    digitalWrite(13, HIGH);
    delay(2000);
    digitalWrite(13, LOW);
  }
}
