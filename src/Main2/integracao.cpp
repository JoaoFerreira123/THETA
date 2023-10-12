#include <Arduino.h>
#include "motores.h"
#include "ultrassonico.h"
#include "mpu.h"
#include "encoderKY040.h"

int printing_delay = 10;

unsigned long int timeON;

void setup() {
  Serial.begin(115200);
  _imu_connect = imu_setup();
  pinMode(PWMA, OUTPUT);
  pinMode(PWMB, OUTPUT);
  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);
  pinMode(BIN1, OUTPUT);
  pinMode(BIN2, OUTPUT);

  // The module already has pullup resistors on board
  pinMode(PIN_A, INPUT);
  pinMode(PIN_B, INPUT);


// We need to monitor both pins, rising and falling for all states
  attachInterrupt(digitalPinToInterrupt(PIN_A), rotary, CHANGE);
  attachInterrupt(digitalPinToInterrupt(PIN_B), rotary, CHANGE);

}

void loop() {
  //getValueUltrassonic(50); 
  //getMPUAngle();
  checkEncoders();
  frente(50);
  //stop();




  
  //delay(1000);

  //delay(50);

}