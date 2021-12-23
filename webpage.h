#ifndef webpage_h
#define webpage_h

#include <Arduino.h>
#include <Preferences.h>
#include "iot.h"

extern String homepage() PROGMEM;
extern String settings() PROGMEM;
extern String doseChart() PROGMEM;
extern String editDose() PROGMEM;
extern String wifi() PROGMEM;
extern String timesetting() PROGMEM;
extern String phone() PROGMEM;
extern String chooseCompartment() PROGMEM;
extern String compartmentsettings(int compID) PROGMEM;

/*! @param delay refresh delay in seconds */
extern String processing(int delay = 3) PROGMEM;
extern String processed() PROGMEM;

#endif