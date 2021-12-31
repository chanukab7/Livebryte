#include "touch.h"

void Touch::pinSetup() {
  pinMode(pin, INPUT);
}

bool Touch::touchCountForced(int count){
    int i=0;

    //using analogRead to count the number of times the touch sensor is triggered
    int prevalue=analogRead(pin);

    while(i<count){
        int proxi=analogRead(pin);
        if(proxi-prevalue>150){
            i+=1;
        }
        prevalue=proxi;
        delay(20);
    }

    if (i==count){
        return true;
    }
    else{
        return false;
    }
}

bool Touch::touchOne(){
    int prevalue=analogRead(pin);
    delay(20);
    int proxi=analogRead(pin);
    
    if (proxi-prevalue>150){
        return true;
    }
    else{
        return false;
    }
}