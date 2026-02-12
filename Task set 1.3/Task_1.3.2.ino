#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

#define UP 2
#define DOWN 3
#define LEFT 6
#define RIGHT 5

int x = 64;
int y = 32;

const int step = 2;   

void setup() {

  pinMode(UP, INPUT_PULLUP);
  pinMode(DOWN, INPUT_PULLUP);
  pinMode(LEFT, INPUT_PULLUP);
  pinMode(RIGHT, INPUT_PULLUP);

  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
}

void loop() {

  if (digitalRead(UP) == LOW) {
    y -= step;
  }

  if (digitalRead(DOWN) == LOW) {
    y += step;
  }

  if (digitalRead(LEFT) == LOW) {
    x -= step;
  }

  if (digitalRead(RIGHT) == LOW) {
    x += step;
  }

  

  if (x < 0) x = SCREEN_WIDTH - step;
  if (x >= SCREEN_WIDTH) x = 0;

  if (y < 0) y = SCREEN_HEIGHT - step;
  if (y >= SCREEN_HEIGHT) y = 0;



  display.clearDisplay();

  display.fillRect(x, y, 8, 8, WHITE);

  display.display();
   
}
