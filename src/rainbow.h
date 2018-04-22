#ifndef rainbow_h
#define rainbow_h

#include <Arduino.h>
#include <FastLED.h>

/**
* Fuellt die LEDs in Regenbogenfarbe entlang des HUE Wertes.
*
* @Author: mnebuhr
* @Since : 20.04.2018

* Parameter:
* leds     : Zeiger auf den Speicherbereich fuer die Farbwerte der LEDs.
* num_leds : Anzahl der LEDs
* hue      : Startwert des Regenbogens.
*/
void rainbow(CRGB* leds, uint8_t num_leds, uint8_t hue);

/**
* Fuegt Glitter hinzu.
**/
void addGlitter(CRGB* leds, uint8_t num_leds, fract8 chanceOfGlitter);

void rainbowWithGlitter(CRGB* leds, uint8_t num_leds, uint8_t hue, fract8 chanceOfGlitter);

#endif