#include "compartment_func.h"

void Compartment::dispenseOne(){

    displayText("Dispensing Medication");

    while(true){

        motorrotate(2, 135);
        delay(3000);
        motorrotate(2, 75);
        delay(1300);
        motorrotate(1, 100);
        delay(700);

        for(int i = 0; i < 3; i++){
            motorrotate(1, 90);

            if(irCountForced(1)){
                motorrotate(0);
                goto end;
            }

            delay(1000);

        }
    }

    end:
        motorrotate(0);
        displayText("Dispensed");
        delay(1000);
        motorrotate(2, 100);
        delay(1000);
        motorrotate(0);
}