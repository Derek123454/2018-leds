#include <Adafruit_NeoPixel.h>

#define LED_COUNT 20

Adafruit_NeoPixel strip = Adafruit_NeoPixel(LED_COUNT, 6, NEO_GRB + NEO_KHZ800);

void setup() {
  strip.begin();
  strip.show();
 
  Serial.begin(9600);
}


void loop() {
  if (Serial.available() >= 3) {
    char red = Serial.read();
    char green = Serial.read();
    char blue = Serial.read();
    uint32_t color = strip.Color(green, red, blue);

    for (int i = 0; i < LED_COUNT; i++) {
      strip.setPixelColor(i, color);
    }

    strip.show();
  }
}
