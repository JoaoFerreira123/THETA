#include <Arduino.h>
#include "VL53_sensors.h"

VL53_sensors sensores;

void setup(){
  Serial.begin(112500);
  sensores.sensorsInit();
}



void loop(){
 sensores.distanceRead();
 Serial.println(sensores.dist[2]);
}   

