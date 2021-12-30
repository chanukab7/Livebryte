#include "rtcfunctions.h"

RTC_DS3231 rtc;

void rtcSetup () {
    long time = millis();
    while(!rtc.begin()){
        if (millis() - time > 5000) {
            Serial.println("Couldn't find RTC");
            break;
        }
    }

    //rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
}

DateTime getTime () {
    return rtc.now();
}

bool timeIsSet (int hour, int minute, int second) {    
    return (getTime().hour() == hour && getTime().minute() == minute && getTime().second() == second);
}

int epochTime () {
    return getTime().secondstime();
}

void setDateTime(int year, int month, int day, int hour, int minute, int second) {
    rtc.adjust(DateTime(year, month, day, hour, minute, second));
}

