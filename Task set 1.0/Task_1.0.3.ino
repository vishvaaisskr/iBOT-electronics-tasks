int led = 9;
int button = 2;

bool ledState = false;
bool lastButtonState = HIGH;

void setup() {
  pinMode(led, OUTPUT);
  pinMode(button, INPUT_PULLUP);
}

void loop() {
  bool currentState = digitalRead(button);

  if (currentState == LOW && lastButtonState == HIGH) {
    ledState = !ledState;
    digitalWrite(led, ledState);
    delay(200);   
  }

  lastButtonState = currentState;
}
