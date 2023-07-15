#include <Arduino.h>
#include <Adafruit_NeoPixel.h>

#define LED_PIN 19
#define NUMPIXELS 60

Adafruit_NeoPixel pixels(NUMPIXELS, LED_PIN, NEO_GRB + NEO_KHZ800); //ultimo argumento eh o tipo do led??


void setup() {

  pixels.begin();
}

void loop() {
  pixels.clear();

  for(int i=0; i<NUMPIXELS; i++) {

    pixels.setPixelColor(i, pixels.Color(0, 150, 0));
    pixels.show();
    delay(10);
  }
}