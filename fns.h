#ifndef fns_h
#define fns_h

#include <DS3231.h>
#include <TimeLib.h>
#include <FastLED.h>

class Fns {
public:
  Fns();
  int countdown(int weekday);
  void resetLED(int NUM_LEDS);
  void LEDnumbers(int num, int section);
};

extern bool century;

extern const int NUM_LEDS;
extern CRGB leds[];

#endif

