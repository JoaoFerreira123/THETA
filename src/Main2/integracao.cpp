#include <Arduino.h>
#include "motores.h"
#include "encoders.h"
#include "ultrassonico.h"
#include "mpu.h"

int printing_delay = 10;

void setup() {
  Serial.begin(115200);
  _imu_connect = imu_setup();
  pinMode(PWMA, OUTPUT);
  pinMode(PWMB, OUTPUT);
  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);
  pinMode(BIN1, OUTPUT);
  pinMode(BIN2, OUTPUT);
}

void loop() {

  getValueEncoderA(printing_delay);
  //getValueEncoderB(printing_delay);
  //getValueUltrassonic(50); 
  //getMPUAngle();
  Serial.println();
  frente(60, 10);
  delay(50);

}