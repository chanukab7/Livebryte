#include "clss.h"
#include "motorfunctions.h"
#include "irfunctions.h"

#include "rtcfunctions.h"
#include "display.h"
#include "images.h"

// #include "touch.h"

#include "gsm.h"
#include "iot.h"
#include "webclient.h"

#define s Serial

//pin definitions
/* int motorpins1[2] = {26, 25};
int irpins[] = {35};

//device definitions
Compartment comp1(1, motorpins1, irpins[0]); */
// Touch touch(34);

void setup() {
  s.begin(9600);

  displaySetup();
  s.println("Display Set");

  rtcSetup();
  s.println("RTC set");

  /* touch.pinSetup();
  s.println("Touch sensor set"); */

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