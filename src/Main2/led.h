
#include <Adafruit_NeoPixel.h>

#define LED_PIN 15
#define NUMPIXELS 61

Adafruit_NeoPixel pixels(NUMPIXELS, LED_PIN, NEO_GRB + NEO_KHZ800); 

// Fill the dots one after the other with a color
void colorWipe(uint32_t c, uint8_t wait) {
  for(uint16_t i=0; i<pixels.numPixels(); i++) {
    pixels.setPixelColor(i, c);
    pixels.show();
    delay(wait);
  }
}




void leds(String mode, int brightness){
    if (mode == "static"){
        pixels.setBrightness(brightness);
        pixels.fill(pixels.Color(119, 0, 200), 1, 60);
        pixels.show();
    }
    if (mode == "fade"){
        pixels.setBrightness(brightness);
        colorWipe(pixels.Color(119, 0, 200), 60); 
    }

    /*
        for(int i=0; i<NUMPIXELS; i++) {
        pixels.setPixelColor(i, pixels.Color(119, 0, 200));
        pixels.show();
    }
    */


}


