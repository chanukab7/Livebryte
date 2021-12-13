#ifndef display_h
#define display_h

#include "rtcfunctions.h"
#include "touch.h"

#include <Arduino.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

void ledonce();


void displaySetup();
void displayTime();
void cuteDisplayTime(Touch touch);
char* returnTime();
void displayDate();
char* returnDate();

/*! @brief Enter a string to pass through to the display
    @param scroll 0 for no scroll, 1 to scroll to right. Recommended to use stopscroll() to stop scrolling. after displaying.
    @param x x axis position of the starting point of the text
    @param y y axis position of the starting point of the text */
void displayText(String text, int txtSize=1, int scroll=0, int x=0, int y=0);
void stopScroll();
void displayImage(unsigned char* image);


#endif