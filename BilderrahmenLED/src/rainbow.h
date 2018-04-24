#ifndef rainbow_h
#define rainbow_h

#include <Arduino.h>
#include <FastLED.h>

void rainbow(CRGB* leds, uint8_t num_leds, uint8_t hue);
void addGlitter(CRGB* leds, uint8_t num_leds, fract8 chanceOfGlitter);
void rainbowWithGlitter(CRGB* leds, uint8_t num_leds, uint8_t hue, fract8 chanceOfGlitter);
void confetti(CRGB* leds, uint8_t num_leds, uint8_t hue); 
void sinelon(CRGB* leds, uint8_t num_leds, uint8_t hue); 
void bpm(CRGB* leds, uint8_t num_leds, uint8_t hue); 
void jungle(CRGB* leds, uint8_t num_leds); 

#endif