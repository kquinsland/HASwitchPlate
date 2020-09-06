#define FASTLED_ESP8266_RAW_PIN_ORDER
#include "FastLED.h"
// Fastled constants
// On the ESP01, GPIO2 is pin 2
// On the D1 Mini, D0 is pin 16
// SEe: https://github.com/esp8266/Arduino/blob/master/variants/d1_mini/pins_arduino.h
//#define DATA_PIN    16

// Trying w/ the NodeMCU
// THIS WORKS w/ the nodeMCU!
// THIS WORKS w/ the D1 Mini
//#define DATA_PIN    D8

// Try D0 on the mini
// This does NOT WORK... and i don't know why
#define DATA_PIN D0

// THIS WORKS w/ D1Mini
#define DATA_PIN D1

// THIS WORKS w/ D1Mini
//#define DATA_PIN    D2

#define COLOR_ORDER GRB
#define NUM_LEDS 20
#define LED_TYPE WS2812B
#define BRIGHTNESS 64
CRGB leds[NUM_LEDS];

void setup()
{
  FastLED.addLeds<LED_TYPE, DATA_PIN, COLOR_ORDER>(leds, NUM_LEDS);
  FastLED.setCorrection(TypicalLEDStrip);
  FastLED.setBrightness(BRIGHTNESS);
  FastLED.clear();
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(115200);
  Serial.println("SETUP OUT");
}

void loop()
{
  anim1();
}

void anim1()
{
  digitalWrite(LED_BUILTIN, LOW); //  Turn the LED on
  fill_solid(leds, NUM_LEDS, CRGB::Red);
  FastLED.show();
  delay(200);

  fill_solid(leds, NUM_LEDS, CRGB::Blue);
  FastLED.show();
  delay(2000);

  fill_solid(leds, NUM_LEDS, CRGB::Green);
  FastLED.show();
  delay(200);

  fill_solid(leds, NUM_LEDS, CRGB::White);
  FastLED.show();
  digitalWrite(LED_BUILTIN, HIGH); //  Turn the LED off
  delay(2000);

  Serial.println("END/WAIT");
}
