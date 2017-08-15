#include "FastLED.h"
#define SUM_LEDS 64
#define DATA_PIN 6
#define DELAY_STD 30
#define BRIGHTNESS_STD 8

CRGBArray<SUM_LEDS> leds;

void setup() {
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, SUM_LEDS);
}

void loop() {  
  // ### EYES ###
  leds[9].r = BRIGHTNESS_STD;
  leds[10].r = BRIGHTNESS_STD;
  leds[13].r = BRIGHTNESS_STD;
  leds[14].r = BRIGHTNESS_STD;
  leds[17].r = BRIGHTNESS_STD;
  leds[18].r = BRIGHTNESS_STD;
  leds[21].r = BRIGHTNESS_STD;
  leds[22].r = BRIGHTNESS_STD;
  // ### NOSE ###
  leds[35].b = BRIGHTNESS_STD;
  leds[36].b = BRIGHTNESS_STD;
  // ### MOUTH ###
  leds[40].g = BRIGHTNESS_STD;
  leds[41].g = BRIGHTNESS_STD;
  leds[46].g = BRIGHTNESS_STD;
  leds[47].g = BRIGHTNESS_STD;
  leds[49].g = BRIGHTNESS_STD;
  leds[50].g = BRIGHTNESS_STD;
  leds[53].g = BRIGHTNESS_STD;
  leds[54].g = BRIGHTNESS_STD;
  leds[58].g = BRIGHTNESS_STD;
  leds[59].g = BRIGHTNESS_STD;
  leds[60].g = BRIGHTNESS_STD;
  leds[61].g = BRIGHTNESS_STD;
  FastLED.show();
}
