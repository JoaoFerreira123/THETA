
#include <Adafruit_NeoPixel.h>

#define LED_PIN 15
#define NUMPIXELS 60

Adafruit_NeoPixel pixels(NUMPIXELS, LED_PIN, NEO_GRB + NEO_KHZ800); 

void leds(int state, int brightness){
    pixels.setBrightness(brightness);
    if(state == 0){
        pixels.clear();
    }
    if(state == 1){
        for(int i=0; i<NUMPIXELS; i++) {
            pixels.setPixelColor(i, pixels.Color(119, 0, 200));
            pixels.show();
            //delay(10);
        }
    }
}

