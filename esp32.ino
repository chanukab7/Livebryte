#include "clss.h"
#include "motorfunctions.h"
#include "irfunctions.h"

#include "rtcfunctions.h"
#include "display.h"
#include "images.h"

#include "gsm.h"
#include "iot.h"
#include "webclient.h"

#define s Serial

void setup() {
  s.begin(9600);

  displaySetup();
  s.println("Display Set");

  rtcSetup();
  s.println("RTC set");

  //compartment setup
  compartmentPinSetup();
  s.println("Compartment setup");

  //wifi setup
  wifisetup();
  s.println(returnsoftAPIP());
  delay(5000);
  s.println(returnLocalIP());

  webclientSetup();
    
}

void loop(){
  
  handleClient();

  switch (s.read()) {
    case 'l':
      s.println(returnLocalIP());
      break;
    case 's':
      s.println(returnsoftAPIP());
      break;
    default:
      break;
  }

  displayTime();

  /* if (!t){
    start = millis();
    t =true;
  }

  if (millis() - start >= 5000){
    Serial.print(getTime().hour(), DEC);
    Serial.print(':');
    Serial.print(getTime().minute(), DEC);
    Serial.print(':');
    Serial.print(getTime().second(), DEC);
    Serial.println();

    t=false;
  } */

    

  
}