#include "irfunctions.h"

bool Compartment::irCountForced(int count){
    int i=0;

    //using analogRead to count the number of times the IR sensor is triggered
    int prevalue=analogRead(ir);

    while(i<count){
        int proxi=analogRead(ir);
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

bool Compartment::irOne(){
    int prevalue=analogRead(ir);
    delay(20);
    int proxi=analogRead(ir);
    
    if (proxi-prevalue>150){
        return true;
    }
    else{
        return false;
    }
}