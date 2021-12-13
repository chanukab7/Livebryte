#ifndef rtcfunctions_h
#define rtcfunctions_h

#include <Wire.h>
#include <RTClib.h>
#include <Arduino.h>

void rtcSetup ();
DateTime getTime ();

/**************************************************************************/
/*!
    @brief  Returns true if current time is equal to the
            given time, false otherwise.
    @param hour hour in 24 hour format.
    @param minute 0-60.
    @param second 0-60. 0 by default
*/
/**************************************************************************/
bool timeIsSet(int hour, int minute, int second=0);

int epochTime ();

void setDateTime(int year=2022, int month=01, int day=01, int hour=00, int minute=00, int second=00);

#endif