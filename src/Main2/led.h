
#include <Adafruit_NeoPixel.h>

#define LED_PIN 15
#define NUMPIXELS 60

Adafruit_NeoPixel pixels(NUMPIXELS, LED_PIN, NEO_GRB + NEO_KHZ800); 

void leds(int brightness){
    pixels.setBrightness(brightness);
    pixels.fill(pixels.Color(119, 0, 200), 1, 60);
    pixels.show();

    /*
        for(int i=0; i<NUMPIXELS; i++) {
        pixels.setPixelColor(i, pixels.Color(119, 0, 200));
        pixels.show();
    }
    */


}


