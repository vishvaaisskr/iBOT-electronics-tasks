#include <LiquidCrystal.h>


LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int ldrPin = A0;
int buzzerPin = 8;

int threshold = 500;  

void setup() {

  lcd.begin(16, 2);
  pinMode(buzzerPin, OUTPUT);

  lcd.print("System Ready");
  delay(2000);
  lcd.clear();
}

void loop() {

  int lightValue = analogRead(ldrPin);

  lcd.clear();

  if (lightValue > threshold) {
    
    lcd.setCursor(0, 0);
    lcd.print("No Interference");
    digitalWrite(buzzerPin, LOW);
  }
  else {
    
    lcd.setCursor(0, 0);
    lcd.print("Interference");
    lcd.setCursor(0, 1);
    lcd.print("Detected!");
    digitalWrite(buzzerPin, HIGH);
  }

  delay(500);
}
