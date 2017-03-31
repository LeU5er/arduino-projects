#include "FastLED.h"
#define NUM_LEDS 60
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
    int sensorValueA0 = analogRead(A0);  // FORWARD-BACKWARD
    int sensorValueA1 = analogRead(A1);  // LEFT-RIGHT
    int tempvar;
    int temppos;

    temppos = sensorValueA0/18;

    //CHANGE COLOR TO GREEN
    tempvar = 0xFF - sensorValueA1;
    if (tempvar < 0) tempvar = 0;
    leds[temppos].g = tempvar;
    
    //CHANGE COLOR TO BLUE
    tempvar = 0xFF-(1023-sensorValueA1);
    if (tempvar < 0) tempvar = 0;
    leds[temppos].b = tempvar;
    
    //CHANGE COLOR TO RED
    if (sensorValueA1 < 512) 
    {
    tempvar = 0xFF-sensorValueA1+512;
    }
    else 
    {
    tempvar = 0xFF-sensorValueA1-512;
    }
    leds[temppos].r = tempvar;
    
    FastLED.show();
}
