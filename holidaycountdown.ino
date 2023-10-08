/*
Author: @michellethemaker
Date: 8 October 2023
            NOTE: I mounted the led sheet upside down. 
            So i had to recode the led functions to account for that.
            Modify the LED lighting code as per your own requirements.
*/
#include <FastLED.h>
#include <TimeLib.h>
#include <DS3231.h>
#include "fns.h"

bool century = false;
Fns fnslib;

#define WKDAY 8

#define LED_PIN     2 //digital
#define NUM_LEDS    65
#define BRIGHTNESS  12
#define LED_TYPE    WS2811
#define COLOR_ORDER GRB
CRGB leds[NUM_LEDS];

#define UPDATES_PER_SECOND 10

int wkday_toggle = 1;
int wkday_toggle_prev = 0;

void setup() {

  pinMode(WKDAY, INPUT);
  Serial.begin(115200);
  FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
  FastLED.setBrightness(  BRIGHTNESS );
}

void loop() {

  if(digitalRead(WKDAY)==LOW){
    wkday_toggle_prev = 1;
  }
  else{
    wkday_toggle_prev = 0; 
  }
  if(wkday_toggle!= wkday_toggle_prev ){
    fnslib.resetLED(NUM_LEDS);
    wkday_toggle = wkday_toggle_prev;
  }
  int count = fnslib.countdown(wkday_toggle);
  
  Serial.print("count: ");
  Serial.println(count);

  int section1 = count/10;
  int section2 = count%10;

  Serial.println(section1);
  Serial.println(section2);
  
  fnslib.LEDnumbers(section2, 0);
  fnslib.LEDnumbers(section1, 13);
  Serial.println("~~~~~~");
  delay(2000);
}


