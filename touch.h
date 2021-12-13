#ifndef touch_h
#define touch_h

#include <Arduino.h>

class Touch {
    public:
    int pin;

    Touch(int pin=35) {
    this->pin = pin;
    }

    void pinSetup();
    
    /*!    @brief forcefully waits until the count is done    */
    bool touchCountForced(int count);

    bool touchOne();

};

#endif