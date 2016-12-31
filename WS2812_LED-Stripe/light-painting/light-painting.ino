/*
//////////////////////////////////////////////////////////
//// Copyright: @LeU5er                               ////
//// EMAIL: publicleu5er@gmail.com                    ////
//// R4P3.NET: @LeU5er (SUPPORT VIA PM)               ////
//// GITHUB: LeU5er                                   ////
//////////////////////////////////////////////////////////
*/

#include <FastLED.h>
#include <animation.h>

//SOME PATTERNS. COMMENT BACK IN, WHAT EVER YOU LIKE
#include "mushroom.h"
//#include "turtle.h"
//#include "YOUR-OWN-PATTERN.h"

#define LED_COUNT 60*5
struct CRGB leds[LED_COUNT];

#define STRIP_OUT    6 // DATA PIN OF LED-STRIP

#define BRIGHT_STEP_COUNT 5
int brightnesSteps[BRIGHT_STEP_COUNT] = {5,15,40,70,93}; // DIFFERENT STEPS OF BRIGHTNESS
int brightness = 4; // MAX BRIGHTNESS AS DEFAULT
int run_mode = 0; // CURRENT RUN MODE (BLINKING OR NOT)
int frameDelay = 30; // Number of ms each frame should be displayed.
int framesDone = 0; // COUNTER OF FINISHED FRAMES (COLUMNS)

void setup()
{  
  LEDS.addLeds<WS2812B, STRIP_OUT, GRB > (leds, LED_COUNT);
  LEDS.showColor(CRGB(0, 0, 0));
  LEDS.setBrightness(brightnesSteps[brightness]);
  LEDS.show();
}

void loop() {{
    animation.draw(leds);
    framesDone++;
  }

  delay(frameDelay);
}

void blackout() {
  for(int led = 0; led < LED_COUNT; led = led + 1) {
    leds[led] = CRGB(0, 0, 0);
  }
   LEDS.show();
}
