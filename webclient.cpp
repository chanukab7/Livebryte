#include "webclient.h"

bool actionDone = false;
unsigned int currentCompWebClient;

// WiFiServer server(80);
WebServer server(80);

void webclientSetup(){
    server.begin();

    server.on("/", sendHomepage);
    server.on("/settings", sendSettings);
    server.on("/settings/wifi", sendWifi);
    server.on("/settings/timesetting", sendTimePage);
    server.on("/settings/phone", sendPhone);
    server.on("/settings/phone/testcall", sendSubmit);
    server.on("/settings/phone/testmsg", sendSubmit);
    server.on("/settings/choosecompartment", sendChooseCompartment);
    server.on("/cs1", sendCS1);
    server.on("/cs2", sendCS2);
    server.on("/cs3", sendCS3);
    server.on("/cs1/calibrate", sendCalibrate);
    server.on("/cs2/calibrate", sendCalibrate);
    server.on("/cs3/calibrate", sendCalibrate);
    server.on("/cs1/dispense", sendDispense);
    server.on("/cs2/dispense", sendDispense);
    server.on("/cs3/dispense", sendDispense);
    server.on("/get", sendSubmit);
}

void sendHomepage(){
    server.send(200, "text/html", homepage());
}

void sendSettings(){
    actionDone = false;
    currentCompWebClient = 0;
    server.send(200, "text/html", settings());
}

void sendWifi(){
    server.send(200, "text/html", wifi());
}

void sendTimePage(){
    server.send(200, "text/html", timesetting());
}

void sendPhone(){
    server.send(200, "text/html", phone());
}

void sendChooseCompartment(){
    actionDone = false;
    server.send(200, "text/html", chooseCompartment());
}

void sendCS1(){
    actionDone = false;
    currentCompWebClient = 1;
    server.send(200, "text/html", compartmentsettings(1));
}

void sendCS2(){
    actionDone = false;
    currentCompWebClient = 2;
    server.send(200, "text/html", compartmentsettings(2));
}

void sendCS3(){
    actionDone = false;
    currentCompWebClient = 3;
    server.send(200, "text/html", compartmentsettings(3));
}

void sendCalibrate(){

    server.send(200, "text/html", processing());
    while(!actionDone){
        switch(currentCompWebClient){
            case 1:
                comp1.calibrate();
                break;
            case 2:
                comp2.calibrate();
                break;
            case 3:
                comp3.calibrate();
                break;
        }
    }
    actionDone =true;
    server.send(200, "text/html", processed());
}

void sendDispense(){

    server.send(200, "text/html", processing());
    while(!actionDone){
        switch(currentCompWebClient){
            case 1:
                comp1.dispenseOne();
                break;
            case 2:
                comp2.dispenseOne();
                break;
            case 3:
                comp3.dispenseOne();
                break;
        }
    }
    actionDone =true;
    server.send(200, "text/html", processed());
}

void sendSubmit(){

    while(!actionDone){
        server.send(200, "text/html", processing());
        String command = server.argName(0);

        if (command == "ssid"){
                String ssidFromServer = server.arg(0);
                String passwordFromServer = server.arg(1);

                Preferences pref;
                pref.begin("wifi", false);
                pref.putString("ssid", ssidFromServer);
                pref.putString("password", passwordFromServer);
                pref.end();

                Serial.println(ssidFromServer.c_str());
                Serial.println(passwordFromServer.c_str());

                WiFi.begin(ssidFromServer.c_str(), passwordFromServer.c_str());
                Serial.println(returnLocalIP());
        }

        else if (command == "phonenumber"){
            String phonenumber = server.arg(0);
            
            Preferences pref;
            pref.begin("phone", false);
            pref.putString("phonenumber", phonenumber);
            pref.end();

        }

        else if (command == "date"){
            const char* tempDate=server.arg(0).c_str();

            const char* tempTime=server.arg(1).c_str();

            setDateTime(tempDate[0], tempDate[1], tempDate[2], tempTime[0], tempTime[1]);
        }

        else{
            Serial.println("Unknown");

        }

        actionDone = true;
    }

    server.send(200, "text/html", processed());
}


void handleClient(){
    server.handleClient();
}