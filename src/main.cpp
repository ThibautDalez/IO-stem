#include <Arduino.h> 
#include <FastLED.h> 

 
#define NUM_LEDS 16 // How many leds in your strip? 

// For led chips like WS2812, which have a data line, ground, and power, you just 
// need to define DATA_PIN.  For led chipsets that are SPI based (four wires - data, clock, 
// ground, and power), like the LPD8806 define both DATA_PIN and CLOCK_PIN 
// Clock pin only needed for SPI based chipsets when not using hardware SPI 

#define DATA_PIN 3

CRGB leds[NUM_LEDS]; // Define the array of leds 


void setup() {  

    FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, NUM_LEDS); // Initialize the LED strip object, specify type, data pin, color order, and number of leds

} 

 

void loop() {  

  // Turn the LED on, then pause
  // Set even indexed LEDs to cyan and odd indexed LEDs to yellow
  for (int i = 0; i < NUM_LEDS; i+=2)
  {
    leds[i] = CRGB(0,100,100);
  }
    for (int i = 1; i < NUM_LEDS; i+=2)
  {
    leds[i] = CRGB(100,100,0);
  }
  FastLED.show(); 
  delay(500); 

   
  // Now turn the LED off, then pause 
  for (int i = 0; i < NUM_LEDS; i++)
  {
    leds[i] = CRGB::Black; 
  }
  FastLED.show(); 
  delay(500); 

} 