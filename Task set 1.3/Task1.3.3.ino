#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

int audioPin = A0;

void setup() {
  Serial.begin(9600);

  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println("OLED not found");
    while(true);
  }

  display.clearDisplay();
  display.display();
}

void loop() {

  int soundValue = analogRead(audioPin);

  // Map sound level to bar height (0 to 32 pixels)
  int barHeight = map(soundValue, 0, 1023, 0, 32);

  display.clearDisplay();

  
  display.drawLine(0, 32, 128, 32, WHITE);

  // Draw bar expanding from center
  display.fillRect(60, 32 - barHeight, 8, barHeight * 2, WHITE);

  display.display();

  delay(30);
}
