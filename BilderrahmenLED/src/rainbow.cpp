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

void confetti(CRGB* leds, uint8_t num_leds, uint8_t hue) 
{
  // random colored speckles that blink in and fade smoothly
  fadeToBlackBy(leds, num_leds, 10);
  int pos = random16(num_leds);
  leds[pos] += CHSV( hue + random8(64), 200, 255);
}
