#ifndef webclient_h
#define webclient_h

#include <WiFi.h>
// #include <WiFiClient.h>
#include <WebServer.h>
#include "webpage.h"
#include <Preferences.h>

#include "clss.h"
#include "rtcfunctions.h"
#include "iot.h"
#include "gsm.h"

extern bool actionDone;

void sendHomepage();
void sendSettings();
void sendWifi();
void sendTimePage();
void sendPhone();
void sendChooseCompartment();
void sendCS1();
void sendCS2();
void sendCS3();
void sendCalibrate();
void sendDispense();
void sendChangeName();
void sendSubmit();

void webclientSetup();
void handleClient();

#endif