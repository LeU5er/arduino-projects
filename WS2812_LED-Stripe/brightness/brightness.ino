#include "FastLED.h"
#define SUM_LEDS 60
#define LED_PIN 3
#define STD_DELAY 250
#define TURBO_DELAY 20

CRGB leds[SUM_LEDS];

int value;

void setup() {
 FastLED.addLeds<NEOPIXEL, LED_PIN>(leds, SUM_LEDS);
 value = 3,96875;
}

void loop() {  
  for(int i = 0; i < SUM_LEDS; i++) {
    leds[i].r = i+value;
    FastLED.delay(TURBO_DELAY);
  }  
  FastLED.show();
  FastLED.delay(STD_DELAY);for(int i = 0; i < SUM_LEDS; i++) {
    leds[i].r = 0;
    leds[i].g = i+value;
    FastLED.delay(TURBO_DELAY);
  }  
  FastLED.show();
  FastLED.delay(STD_DELAY);
  for(int i = 0; i < SUM_LEDS; i++) {
    leds[i].g = 0;
    leds[i].b = i+value;
    FastLED.delay(TURBO_DELAY);
  }  
  FastLED.show();
  FastLED.delay(STD_DELAY);
  for(int i = 0; i < SUM_LEDS; i++) {
    leds[i].r = 0;
    leds[i].b = 0;
    leds[i].g = 0;
    FastLED.delay(TURBO_DELAY);
  }  
  FastLED.show();
  FastLED.delay(STD_DELAY);
}
