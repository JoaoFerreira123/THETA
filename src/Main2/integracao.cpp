#include <Arduino.h>
#include "motores.h"
#include "ultrassonico.h"
#include "mpu.h"
#include "encoderKY040.h"
#include "VL53.h"
#include "upload.h"
#include "led.h"

int printing_delay = 10;

unsigned long int timeON;

VL53_sensors sensores;

void setup() {
  Serial.begin(115200);
  upload_OTA("Oi_A822", "MchCM3TM");
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

  sensores.sensorsInit();

  pixels.begin();
}

void loop() {
  getValueUltrassonic(0); 
  getMPUAngle();
  //checkEncoders();
  //Serial.println();
  //frente(50);
  //stop();
  sensores.distanceRead();
  Serial.print(sensores.dist[0]);
  Serial.print(" ");
  Serial.print(sensores.dist[1]);
  Serial.print(" ");
  Serial.print(sensores.dist[2]);
  Serial.println(" ");

  leds(1, 50);





  
  //delay(1000);

  //delay(50);

}