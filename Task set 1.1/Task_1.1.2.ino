void setup() {
  Serial.begin(9600);
}

void loop() {
  int light = analogRead(A1);
  Serial.println(light);
  delay(200);
}
