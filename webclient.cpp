#include "webclient.h"

bool actionDone = false;
unsigned int currentCompWebClient;

// WiFiServer server(80);
WebServer server(80);

void webclientSetup(){
    server.begin();

    server.on("/", sendHomepage);
    server.on("/settings", sendSettings);
    server.on("/settings/dosechart", sendDoseChart);
    server.on("/settings/dosechart/editdose/", sendEditDose);
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
    server.on("/settings/dosechart/editdose/get", sendSubmitEditDose);
    
}

void sendHomepage(){
    server.send(200, "text/html", homepage());
}

void sendSettings(){
    actionDone = false;
    currentCompWebClient = 0;
    server.send(200, "text/html", settings());
}

void sendDoseChart(){
    server.send(200, "text/html", doseChart());
}

void sendEditDose(){
    server.send(200, "text/html", editDose());
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
            String date = server.arg(0);
            String time = server.arg(1);

            char dateChar[date.length()+1];
            char timeChar[time.length()+1];

            strcpy (dateChar, date.c_str());
            strcpy (timeChar, time.c_str());

            int year = (dateChar[0]-48)*1000 + (dateChar[1]-48)*100 + (dateChar[2]-48)*10 + (dateChar[3]-48);
            int month = (dateChar[5]-48)*10 + (dateChar[6]-48);
            int day = (dateChar[8]-48)*10 + (dateChar[9]-48);
            int hour = (timeChar[0]-48)*10 + (timeChar[1]-48);
            int minute = (timeChar[3]-48)*10 + (timeChar[4]-48);

            Serial.println(year);
            Serial.println(month);
            Serial.println(day);

            Serial.println(hour);
            Serial.println(minute);

            setDateTime(year, month, day, hour, minute, 0);
            
            
        }

        else if (command == "dose"){
            String dose = server.arg(0);
            String time = server.arg(1);

            Preferences pref;
            pref.begin("dose", false);
            pref.putString("dose", dose);
            pref.putString("time", time);
            pref.end();

        }

        else if (command == "dosechart"){
            String dose = server.arg(0);
            String time = server.arg(1);

            Preferences pref;
            pref.begin("dosechart", false);
            pref.putString("dose", dose);
            pref.putString("time", time);
            pref.end();

        }

        else if (command == "comp1"){
            String dose = server.arg(0);
            String time = server.arg(1);

            Preferences pref;
            pref.begin("comp1", false);
            pref.putString("dose", dose);
            pref.putString("time", time);
            pref.end();

        }

        else if (command == "comp2"){
            String dose = server.arg(0);
            String time = server.arg(1);

            Preferences pref;
            pref.begin("comp2", false);
            pref.putString("dose", dose);
            pref.putString("time", time);
            pref.end();

        }

        else if (command == "comp3"){
            String dose = server.arg(0);
            String time = server.arg(1);

            Preferences pref;
            pref.begin("comp3", false);
            pref.putString("dose", dose);
            pref.putString("time", time);
            pref.end();

        }

        else{
            Serial.println("Unknown");

        }

        actionDone = true;
    }

    server.send(200, "text/html", processed());
}

void sendSubmitEditDose(){
    while(!actionDone){
        server.send(200, "text/html", processing());
        String command = server.argName(0);

        Preferences pref;

        if (server.arg(0)=="1"){
            pref.begin("doseslot1", false);
        }
        else if (server.arg(0)=="2"){
            pref.begin("doseslot2", false);
        }
        else if (server.arg(0)=="3"){
            pref.begin("doseslot3", false);
        }
        else{
            break;
        }

        pref.putString("time", server.arg(1));
        pref.putUInt("comp1", server.arg(2).toInt());
        pref.putUInt("comp2", server.arg(3).toInt());
        pref.putUInt("comp3", server.arg(4).toInt());

        pref.end();

        actionDone = true;
    }

    server.send(200, "text/html", processed());
}

void handleClient(){
    server.handleClient();
}