#include <Arduino.h>
#include "motores.h"
#include "ultrassonico.h"
#include "mpu.h"
//#include "encoderKY040.h"
#include "VL53.h"
#include "upload.h"
#include "led.h"
#include "encoder.h"

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
  

  sensores.sensorsInit();

  pixels.begin();
  
  pinMode(PinDT, INPUT);
  pinMode(PinCLK, INPUT);
  PreviousCLK=digitalRead(PinCLK);
  PreviousDATA=digitalRead(PinDT);
}

void loop() {
  Serial.print("U" + String(getValueUltrassonic(0)) + " ");

  Serial.print("M" + String(getMPUAngle()) + " ");

  Serial.print("EA" + String(encoder1()) + " ");

  //frente(50);
  //stop();
   
   
  sensores.distanceRead();
  Serial.print(sensores.dist[0]);
  Serial.print(" ");
  Serial.print(sensores.dist[1]);
  Serial.print(" ");
  Serial.print(sensores.dist[2]);
  Serial.println(" ");
  

  

  leds(20);


  //ENCODER COM ULT + MPU + MOTOR OK, SEM DELAY, MAS JUNTO COM OS VL's NÃO FUNCIONA DIREITO
  //Parece que os VLs atrasam a leitura dos outros sensores e o encoder não consegue atualizar





}





