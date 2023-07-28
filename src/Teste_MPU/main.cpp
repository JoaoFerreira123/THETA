#include <Arduino.h>
#include "mpu.h"


bool _imu_connect; 
bool _connect = false;

#define pi 3.14159265359



void setup(){

  Serial.begin(115200);

  // check that the IMU initializes correctly
  _imu_connect = imu_setup();
}


void loop(){

  float* imu_ypr = imu_get_ypr();  
  //retunr from + pi to -pi 
  Serial.print("Orientation ");
  //Print YAW angle, converted from RAD to dregrees
  Serial.print(float(imu_ypr[0])*180/pi, 5);

  Serial.println("");
  
}   