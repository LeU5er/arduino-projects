//////////////////////////////////////////////////////////
//// This little program is for Arduino together with ////
//// the LED-Strip WS2812.                            ////
//// Copyright: @LeU5er                               ////
//// EMAIL: publicleu5er@gmail.com                    ////
//// R4P3.NET: @LeU5er (SUPPORT VIA PM)               ////
//// GITHUB: LeU5er                                   ////
//////////////////////////////////////////////////////////

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
    int sensorValueA0 = analogRead(A0);  // vor-zurueck
    int sensorValueA1 = analogRead(A1);  // links-rechts
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
