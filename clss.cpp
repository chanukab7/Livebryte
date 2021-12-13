#include  "clss.h"

#include "irfunctions.h"
#include "motorfunctions.h"
#include "display.h"

int motorpins1[2] = {13, 12};
int motorpins2[2] = {14, 27};
int motorpins3[2] = {26, 25};
int irpins[] = {33, 32, 35};

Compartment comp1(1, motorpins1, irpins[0]);
Compartment comp2(2, motorpins2, irpins[1]);
Compartment comp3(3, motorpins3, irpins[2]);

void compartmentPinSetup(){
    comp1.compSetup();
    comp2.compSetup();
    comp3.compSetup();
}

// int Compartment::defaultSpeed=100;
String Compartment::returnCOMPIDforPref(){
    switch (Compartment::compartmentID){
        case 1:{
            return "comp1";
            break;
        }
        case 2:{
            return "comp2";
            break;
        }
        case 3:{
            return "comp3";
            break;
        }
        default:
            break;
    }
}

void Compartment::saveCalibratedDelay(int CD){
    Preferences pref;
    switch (compartmentID){
        case 1:{
            pref.begin("comp1", false);
            break;
        }
        case 2:{
            pref.begin("comp2", false);
            break;
        }
        case 3:{
            pref.begin("comp3", false);
            break;
        }
        default:
            break;
    }

    pref.putInt("calibrated_delay", calibrated_delay);
    pref.end();
}

void Compartment::compSetup(){
    pinMode(this->motor[0], OUTPUT);
    pinMode(this->motor[1], OUTPUT);
    pinMode(this->ir, INPUT);
}

void Compartment::calibrate(int speed){
    displayText("Calibrating...", 2);
    Serial.println("Calibrating...");

    bool calibrated=false;

    int del = 4000;

    int cycle = 1;
    while(true){

        if (del < 500){
            goto end;
        }

        if (cycle % 3 == 0){
        shake(5, 100);
        }

        motorrotate(2, 135);
        delay(3000);
        motorrotate(2, 75);
        delay(del);
        // motorrotate(1, 100);
        // delay(700);

        unsigned long start = millis();

        while(millis()-start<=5000){
            motorrotate(1, speed);

            if(irOne()){
                motorrotate(0);
                shake(3, 100);
                calibrated=true;
                goto end;
            }

        }

        cycle +=1;
        del-=250;
    }

    end:{
        motorrotate(0);
        if(calibrated){
            displayText("Calibration Complete.. Feel free to place the pill back in the container", 1);
            calibrated_delay=del;
            saveCalibratedDelay(calibrated_delay);
        }
            
        else{
            displayText("Calibration Failed.. Please try again", 1);
        }

        delay(1000);
        motorrotate(2, 100);
        delay(1000);
        motorrotate(0);
    }
}

void Compartment::shake(int times, int speed){

    int del=100;

    for(int i=0; i<times; i++){
        motorrotate(1, speed);
        delay(del);
        motorrotate(2, speed);
        delay(del);
    }

    motorrotate(0);
}

void Compartment::dispenseOne(int speed){

    displayText("Dispensing Medication");
    bool failed=false;
    int cycle=1;
    int del=calibrated_delay;

    while(true){

        if (cycle % 3 == 0){
            shake(5, 100);
        }

        if (cycle % 2 ==0){
            del -= 250;
            calibrated_delay=del;
            saveCalibratedDelay(calibrated_delay);
        }

        if (del < 250){
            failed=true;
            goto end;
        }

        motorrotate(2, 135);
        delay(3000);
        motorrotate(2, 75);
        delay(del);
        motorrotate(1, 100);
        delay(700);

        unsigned long start = millis();

        while(millis()-start<=5000){
            motorrotate(1, speed);

            if(irOne()){
                motorrotate(0);
                shake(3, 100);
                
                goto end;
            }

        }

        cycle++;
    }

    end:
        motorrotate(0);
        if (failed){
            displayText("Dispensing Failed.. Please try again", 1);
        }
        else{
            displayText("Medication Dispensed", 1);
        }
        delay(1000);
        motorrotate(2, 100);
        delay(1000);
        motorrotate(0);
}