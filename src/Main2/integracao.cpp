#include <Arduino.h>
#include "motores.h"
#include "encoders.h"
#include "ultrassonico.h"
#include "mpu.h"


void setup() {
  Serial.begin(115200);
  _imu_connect = imu_setup();
}

void loop() {

  getValueEncoderA();
  getValueEncoderB();
  getValueUltrassonic(50); 
  getMPUAngle();
  Serial.println();

}