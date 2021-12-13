#include "motorfunctions.h"

void Compartment::motorrotate(int dire, int speed){

  int pin1=motor[0];
  int pin2=motor[1];
  
  if (dire==0){
    analogWrite(pin1, 0);
    analogWrite(pin2, 0);
  }

   if (dire==1){
    analogWrite(pin1, speed);
    analogWrite(pin2, 0);
  }

   if (dire==2){
    analogWrite(pin1, 0);
    analogWrite(pin2, speed);
  }
}