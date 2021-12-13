#ifndef iot_h
#define iot_h

#include <WiFi.h>
#include <WiFiAP.h>

#include <Preferences.h>


extern const char* ssid;
extern const char* password;

extern const char* hotspotssid;
extern const char* hotspotpassword;

void wifisetup();
IPAddress returnLocalIP();
IPAddress returnsoftAPIP();

#endif