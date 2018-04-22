#include "rainbow.h"

void rainbow(CRGB* leds, uint8_t num_leds, uint8_t hue) {
	fill_rainbow( leds, num_leds, hue, 7);
}

void addGlitter(CRGB* leds, uint8_t num_leds, fract8 chanceOfGlitter) 
{
  if( random8() < chanceOfGlitter) {
    leds[ random16(num_leds) ] += CRGB::White;
  }
}

void rainbowWithGlitter(CRGB* leds, uint8_t num_leds, uint8_t hue, fract8 chanceOfGlitter) 
{
  // built-in FastLED rainbow, plus some random sparkly glitter
  rainbow(leds, num_leds, hue);
  addGlitter(leds, num_leds, chanceOfGlitter);
}
