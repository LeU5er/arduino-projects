#include "FastLED.h"
#define SUM_LEDS 60
#define LED_PIN 3
#define BRIGHTNESS_STD 31

CRGBArray<SUM_LEDS> leds;

float value;
int   led_pos;

void setup() {
 FastLED.addLeds<NEOPIXEL, LED_PIN>(leds, SUM_LEDS);
 value = 0;
}

void loop() {  

  for(int i = 0; i < SUM_LEDS; i++) {
    leds[i].r = 0;
    leds[i].b = 0;
    leds[i].g = 0;
  }
  
  led_pos = int( sin(value)*28 + 30 );
   
  leds[led_pos-1].r = BRIGHTNESS_STD;
  leds[led_pos+0].b = BRIGHTNESS_STD;
  leds[led_pos+1].g = BRIGHTNESS_STD;
   
  led_pos = int( cos(value)*28 + 30 );
   
  leds[led_pos-1].r = BRIGHTNESS_STD;
  leds[led_pos+0].b = BRIGHTNESS_STD;
  leds[led_pos+1].g = BRIGHTNESS_STD;

  FastLED.show();

  value = value + 0.005 ;
  if (value > 2 * 3.14) value = 0;
}
