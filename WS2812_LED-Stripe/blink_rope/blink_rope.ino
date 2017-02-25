#include "FastLED.h"
#define SUM_LEDS 60
#define LED_PIN 3
#define BRIGHTNESS_STD 63
#define STD_DELAY 250

CRGB leds[SUM_LEDS];

void setup() {
 FastLED.addLeds<NEOPIXEL, LED_PIN>(leds, SUM_LEDS);
}

void loop() {
  for(int i = 0; i < SUM_LEDS; i++) {    
     if (i % 2 == 0) {
      leds[i].g = BRIGHTNESS_STD;
     }else {
        leds[i].g = 0;
      }
  }
  for(int i = 1; i < SUM_LEDS; i++) {    
     if (i % 2 == 0) {
        leds[i].r = 0;
     }else {        
        leds[i].r = BRIGHTNESS_STD;
      }
  }
  FastLED.show();
  FastLED.delay(STD_DELAY);
  for(int i = 0; i < SUM_LEDS; i++) {    
     if (i % 2 == 0) {
      leds[i].r = BRIGHTNESS_STD;
     }else {
        leds[i].r = 0;
      }
  }
  for(int i = 1; i < SUM_LEDS; i++) {    
     if (i % 2 == 0) {
        leds[i].g = 0;
     }else {        
        leds[i].g = BRIGHTNESS_STD;
      }
  }
  FastLED.show();
  FastLED.delay(STD_DELAY);
}
