#include "display.h"

#include "images.h"

char monthsOfTheYearShort[12][4] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

Adafruit_SSD1306 display(128, 64, &Wire, -1);

void ledonce(){
    pinMode(2, OUTPUT);
    digitalWrite(2, HIGH);
    delay(1000);
    digitalWrite(2, LOW);
    delay(1000);
}

void displaySetup(){
    if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3D for 128x64
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
    }
    delay(2000);
}

char* returnTime(){

    char time[10];
    sprintf(time, "%02d:%02d:%02d", getTime().hour(), getTime().minute(), getTime().second());

    return time;
}

void displayTime(){
    display.clearDisplay();
    display.setTextSize(2);
    display.setTextColor(WHITE);
    display.setCursor(15, 30);

    char time[10];
    sprintf(time, "%02d:%02d:%02d", getTime().hour(), getTime().minute(), getTime().second());

    //display.println(returnTime());
    display.println(time);

    display.display();
}

void displayDate(){
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(0, 0);

    char date[20];
    sprintf(date, "%02d %s %04d", getTime().day(), monthsOfTheYearShort[getTime().month() - 1], getTime().year());

    display.println(date);
    display.display();
}

char* returnDate(){

    char date[20];
    sprintf(date, "%02d %s %04d", getTime().day(), monthsOfTheYearShort[getTime().month() - 1], getTime().year());

    return date;
}

void displayText(String text, int txtSize, int scroll, int x, int y){
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(0, 10);

    if (scroll==1){
        display.startscrollright(0x00, 0x0F);
    }

    display.println(text);
    display.display();
}

void displayImage(unsigned char* image){
    display.clearDisplay();
    display.drawBitmap(0, 0, image, 128, 64, WHITE);
    display.display();
}

void cuteDisplayTime(Touch touch){
    displayTime();

    if(touch.touchOne()){
        displayImage(ice_bear);
        delay(1000);
        displayImage(inverted_ice_bear);
        delay(1000);
    }
}

void stopScroll(){
    display.stopscroll();
}