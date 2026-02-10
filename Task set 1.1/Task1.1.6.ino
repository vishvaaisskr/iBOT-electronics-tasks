void setup() {
  pinMode(2, INPUT);     
  pinMode(13, OUTPUT);  
  Serial.begin(9600);
}

void loop() {
  int value = digitalRead(2);

  Serial.println(value);

  if(value == HIGH) {
    digitalWrite(13, HIGH);   
  } else {
    digitalWrite(13, LOW);    
  }

  delay(200);
}
