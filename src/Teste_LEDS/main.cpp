#include <Arduino.h>
#include <Adafruit_NeoPixel.h>

#define LED_PIN 15
#define NUMPIXELS 60

Adafruit_NeoPixel pixels(NUMPIXELS, LED_PIN, NEO_GRB + NEO_KHZ800); //ultimo argumento eh o tipo do led??


void setup() {
  pixels.setBrightness(50);
  pixels.begin();

}

void loop() {
  //pixels.clear();

  for(int i=0; i<NUMPIXELS; i++) {

    pixels.setPixelColor(i, pixels.Color(119, 0, 200));
    pixels.show();
    //delay(10);
  }
}