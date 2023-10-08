#include "fns.h"

DS3231 myRTC;
Fns::Fns() {
  // Constructor logic, (if needed)
}

int Fns::countdown(int weekday) {
  
  TimeElements launch;
  TimeElements today;
  launch.Day = 12;
  launch.Month = 12;
  launch.Year = CalendarYrToTm(2023);
  today.Day = myRTC.getDate();
  today.Month = myRTC.getMonth(century);
  today.Year = CalendarYrToTm(2023);
  time_t launchtime = makeTime(launch);
  time_t nowtime = makeTime(today);
  int daysleft = ((launchtime - nowtime)/86400)-2;
  if(weekday == 0){
    Serial.print("weeks left: ");
    daysleft = floor(daysleft/7);
  }
  else{
  Serial.print("days left: ");
  }
  Serial.println(daysleft);
  return daysleft; 
  
}

  //=================LIGHT FUNCTIONS===============

  void Fns::resetLED(int NUM_LEDS){
  for (int j = 0; j <=NUM_LEDS; j++)
    {
      leds[j] = CRGB::Black;//blink to reset lights
    }
}

void Fns::LEDnumbers(int num, int section){ //section: num of leds to skip to get to the next '7segment'

uint8_t brightness = 255;
CRGB color = CRGB::DeepPink; //;DarkOrange
CRGB black = CRGB::Black;

switch(num){
case 0:
  for (int i = 0; i <=11; i++)
          {
            leds[i+section] = color;
          }
  FastLED.show();
  return;
  
case 1:
  for (int i = 8; i <=11; i++)
          {
            leds[i+section] = color;
          }
          leds[0+section] = color;
  FastLED.show();
  return;

case 2:
  for (int i = 0; i <=4; i++)
          {
            leds[i+section] = color;
          }
  for (int i = 6; i <=10; i++)
          {
            leds[i+section] = color;
          }
  leds[12+section] = color;
  FastLED.show();
  return;

case 3:
  for (int i = 0; i <=2; i++)
          {
            leds[i+section] = color;
          }
  for (int i = 6; i <=12; i++)
          {
            leds[i+section] = color;
          }
  FastLED.show();
  return;

case 4:
  leds[0+section] = color;
  for (int i = 4; i <=6; i++)
          {
            leds[i+section] = color;
          }

    for (int i = 8; i <=12; i++)
          {
            leds[i+section] = color;
          }
  FastLED.show();
  return;

case 5:
  for (int i = 0; i <=2; i++)
          {
            leds[i+section] = color;
          }
  for (int i = 4; i <=8; i++)
          {
            leds[i+section] = color;
          }
  for (int i = 10; i <=12; i++)
          {
            leds[i+section] = color;
          }
  FastLED.show();
  return;

case 6:
  for (int i = 0; i <=8; i++)
          {
            leds[i+section] = color;
          }
  for (int i = 10; i <=12; i++)
          {
            leds[i+section] = color;
          }
  FastLED.show();
  return;

case 7:
  leds[0+section] = color;
  for (int i = 6; i <=11; i++)
          {
            leds[i+section] = color;
          }
  FastLED.show();
  return;

case 8:
  for (int i = 0; i <=12; i++)
          {
            leds[i+section] = color;
          }
  FastLED.show();
  return;

case 9:
  for (int i = 0; i <=2; i++)
          {
            leds[i+section] = color;
          }
  for (int i = 4; i <=12; i++)
          {
            leds[i+section] = color;
          }
  FastLED.show();
  return;

case 404:
  for (int i = 0; i <=12; i++)
          {
            leds[i+section] = black;
          }
          Serial.println("off");
  FastLED.show();
  //OFF DOTS
  return;
  
default:
  for (int i = 0; i <=11; i++)
          {
            leds[i+section] = color;
          }
  FastLED.show();
  return;
  Serial.println("wtf where number");
  return;
}

Serial.print(num);
Serial.println(" is the number");

}
