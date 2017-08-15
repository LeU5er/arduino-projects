#include "FastLED.h"
#define SUM_LEDS 64
#define LED_PIN 6
#define DELAY_STD 30
#define DELAY_TURBO 5
#define BRIGHTNESS_STD 4

CRGBArray<SUM_LEDS> leds;

void setup() {
  FastLED.addLeds<NEOPIXEL, LED_PIN>(leds, SUM_LEDS);
}

void loop() {  
  // ########## FIRST ANIMATION ##########
  // OVERWRITE BRIGHTNESS OF COLORS RED, BLUE, GREEN WITH 0
  for(int i = 0; i < SUM_LEDS; i++) {
    leds[i].r = 0;
    leds[i].b = 0;
    leds[i].g = 0;
    FastLED.show();
  }
  // COLOR RED FROM 0 TO 30
  for(int i = 0; i < SUM_LEDS/2; i++) {
    leds[i].r = BRIGHTNESS_STD;
    leds[SUM_LEDS-i].r = BRIGHTNESS_STD;
    FastLED.show();
    delay(DELAY_STD);
  }
  // OVERWRITE BRIGHTNESS OF COLOR RED WITH 0
  for(int i = 0; i < SUM_LEDS/2; i++) {
    leds[i].r = 0;
    leds[SUM_LEDS-i].r = 0;
    FastLED.show();
    delay(DELAY_STD);
  }
  // COLOR BLUE FROM 0 TO 30
  for(int i = 0; i < SUM_LEDS/2; i++) {
    leds[i].b = BRIGHTNESS_STD;
    leds[SUM_LEDS-i].b = BRIGHTNESS_STD;
    FastLED.show();
    delay(DELAY_STD);
  }
  // OVERWRITE BRIGHTNESS OF COLOR BLUE WITH 0
  for(int i = 0; i < SUM_LEDS/2; i++) {
    leds[i].b = 0;
    leds[SUM_LEDS-i].b = 0;
    FastLED.show();
    delay(DELAY_STD);
  }
  // COLOR GREEN FROM 0 TO 30
  for(int i = 0; i < SUM_LEDS/2; i++) {
    leds[i].g = BRIGHTNESS_STD;
    leds[SUM_LEDS-i].g = BRIGHTNESS_STD;
    FastLED.show();
    delay(DELAY_STD);
  }
  // OVERWRITE BRIGHTNESS OF COLOR GREEN WITH 0
  for(int i = 0; i < SUM_LEDS/2; i++) {
    leds[i].g = 0;
    leds[SUM_LEDS-i].g = 0;
    FastLED.show();
    delay(DELAY_STD);
  }
  
  // ########## SECOND ANIMATION ##########
  // OVERWRITE BRIGHTNESS OF COLORS RED, BLUE, GREEN WITH 0
  for(int i = 0; i < SUM_LEDS; i++) {
    leds[i].r = 0;
    leds[i].b = 0;
    leds[i].g = 0;
    FastLED.show();
  }
  // COLOR RED FROM 0 TO 30 & COLOR BLUE FROM 60 TO 30
  for (int i = 0; i < SUM_LEDS/2; i++) {
    leds[i].r = BRIGHTNESS_STD;
    leds[SUM_LEDS-i].b = BRIGHTNESS_STD;
    FastLED.show();
    delay(DELAY_STD);
  }
  // OVERWRITE BRIGHTNESS OF COLORS RED, BLUE WITH 0
  for(int i = 0; i < SUM_LEDS/2; i++) {
    leds[i].r = 0;
    leds[SUM_LEDS-i].b = 0;
    FastLED.show();
    delay(DELAY_STD);
  }
  // COLOR RED FROM 30 TO 60 & COLOR BLUE FROM 30 TO 0
  for (int i = 0; i < SUM_LEDS/2; i++) {
    leds[31+i].r = BRIGHTNESS_STD;
    leds[30-i].b = BRIGHTNESS_STD;
    FastLED.show();
    delay(DELAY_STD);
  }
}
