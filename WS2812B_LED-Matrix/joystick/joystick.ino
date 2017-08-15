#include "FastLED.h"
#define NUM_LEDS 64
#define LED_PIN 6

CRGBArray<NUM_LEDS> leds;

void setup() {
  FastLED.addLeds<NEOPIXEL, LED_PIN>(leds, NUM_LEDS);
}

void loop() {

  for(int i = 0; i < NUM_LEDS; i++) {
    leds[i].r = 0;
    leds[i].g = 0;
    leds[i].b = 0;
  }
    int sensorValueA0 = analogRead(A0);  // vor-zurueck
    int sensorValueA1 = analogRead(A1);  // links-rechts
    int tempvar;
    int temppos;

    temppos = sensorValueA0/18;

    //gruen
    tempvar = 0xFF - sensorValueA1;
    if (tempvar < 0) tempvar = 0;
    leds[temppos].g = tempvar;
    leds[temppos+1].b = tempvar;
    
    //blau
    tempvar = 0xFF-(1023-sensorValueA1);
    if (tempvar < 0) tempvar = 0;
    leds[temppos].b = tempvar;
    leds[temppos+1].r = tempvar;
    
    //rot
    if (sensorValueA1 < 512) 
    {
    tempvar = 0xFF-sensorValueA1+512;
    }
    else 
    {
    tempvar = 0xFF-sensorValueA1-512;
    }
    leds[temppos].r = tempvar;
    leds[temppos+1].g = tempvar;
    
    FastLED.show();
}
