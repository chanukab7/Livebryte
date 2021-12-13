#include "iot.h"

#define w WiFi

//existing wifi router
const char* ssid = "esp32";
const char* password = "espwroom32";

//wifi hotspot
const char* hotspotssid="LiveBryte";
const char* hotspotpassword="12345678";

void wifisetup(){
    w.softAP(hotspotssid, hotspotpassword);

    Preferences pref;
    pref.begin("wifi", true);
    if (pref.getString("ssid", "") != ""){
        w.begin(pref.getString("ssid", "").c_str(), pref.getString("password", "").c_str());
        pref.end();
    }
    else {
        w.begin(ssid, password);
    }
    
}

IPAddress returnLocalIP(){
    return w.localIP();
}

IPAddress returnsoftAPIP(){
    return w.softAPIP();
}