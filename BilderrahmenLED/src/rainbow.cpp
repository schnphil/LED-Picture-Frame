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
void sinelon(CRGB* leds, uint8_t num_leds, uint8_t hue)
{
  // a colored dot sweeping back and forth, with fading trails
  fadeToBlackBy( leds, num_leds, 20);
  int pos = beatsin16( 13, 0, num_leds-1 );
  leds[pos] += CHSV( hue, 255, 192);
}

void bpm(CRGB* leds, uint8_t num_leds, uint8_t hue)
{
  // colored stripes pulsing at a defined Beats-Per-Minute (BPM)
  uint8_t BeatsPerMinute = 62;
  CRGBPalette16 palette = PartyColors_p;
  uint8_t beat = beatsin8( BeatsPerMinute, 64, 255);
  for( int i = 0; i < num_leds; i++) { //9948
    leds[i] = ColorFromPalette(palette, hue+(i*2), beat-hue+(i*10));
  }
}

void jungle(CRGB* leds, uint8_t num_leds) {
  // eight colored dots, weaving in and out of sync with each other
  fadeToBlackBy( leds, num_leds, 20);
  byte dothue = 0;
  for( int i = 0; i < 8; i++) {
    leds[beatsin16( i+7, 0, num_leds-1 )] |= CHSV(dothue, 200, 255);
    dothue += 32;
  }
}