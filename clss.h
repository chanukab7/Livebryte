#ifndef clss_h
#define clss_h

#include <Arduino.h>
#include <Preferences.h>

static int defaultSpeed = 100;

class Compartment{
    public:
    unsigned int compartmentID;
    String name;
    int* motor;
    int ir;

    /*! @brief intialize compartment
        @param compnumber should be either 1 2 or 3 as only 3 compartments
        @param motorpin should be an array containing 2 pin numbers
        @param irPin ir pin corresponding to the container  */

    Compartment(unsigned int compnumber, int motorpin[2], int irPin){
        this->motor=motorpin;
        this->ir=irPin;

        this->compartmentID=compnumber;

        Preferences pref;
        switch (compnumber){
            case 1:{
                pref.begin("comp1", true);
                break;
            }
            case 2:{
                pref.begin("comp2", true);
                break;
            }
            case 3:{
                pref.begin("comp3", true);
                break;
            }
            default:
                break;
        }

        name = pref.getString("name");
        calibrated_delay = pref.getInt("calibrated_delay");
        pref.end();
    }

    //pinMode setup for the compartments
    void compSetup();
    String returnCOMPIDforPref();

    //motor functions
    void motorrotate(int dire, int speed=50);

    //ir functions
    //! @brief waits forcefully until IR detects one pill
    bool irCountForced(int count);
    bool irOne();


    int calibrated_delay;
    void saveCalibratedDelay(int CD);
    //! @brief calibrates backward rotation delay according to the pill in the compartment
    void calibrate(int speed=defaultSpeed);

    //compartment functions
    void dispenseOne(int speed=defaultSpeed);
    void shake(int times=3, int speed=90);

};

extern Compartment comp1;
extern Compartment comp2;
extern Compartment comp3;

void compartmentPinSetup();

#endif