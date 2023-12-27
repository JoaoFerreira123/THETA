#include <Arduino.h>
#include "motores.h"
#include "ultrassonico.h"
#include "mpu.h"
#include "VL53.h"
#include "upload.h"
#include "led.h"
#include "encoder.h"

VL53_sensors sensores;

void setup() {
  Serial.begin(115200);
  upload_OTA("Oi_A822", "MchCM3TM"); // Wifi Credentials
  _imu_connect = imu_setup(); //Init MPU

  //Definitions Motors Pins
  pinMode(PWMA, OUTPUT);
  pinMode(PWMB, OUTPUT);
  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);
  pinMode(BIN1, OUTPUT);
  pinMode(BIN2, OUTPUT);
  

  sensores.sensorsInit(); //Init VL's

  pixels.begin(); //Init LEDs
  
  //Definitions Encoders A and B
  pinMode(PinDT_A, INPUT);
  pinMode(PinCLK_A, INPUT);
  PreviousCLK_A=digitalRead(PinCLK_A);
  PreviousDATA_A=digitalRead(PinDT_A);

  pinMode(PinDT_B, INPUT);
  pinMode(PinCLK_B, INPUT);
  PreviousCLK_B=digitalRead(PinCLK_B);
  PreviousDATA_B=digitalRead(PinDT_B);

}

void loop() {
  Serial.print("U" + String(getValueUltrassonic(0)) + " ");

  Serial.print("M" + String(getMPUAngle()) + " ");

  Serial.print("EA" + String(encoderA()) + " ");

  Serial.print("EB" + String(encoderB()) + " ");
  Serial.println();

  //frente(50);
  //stop();
   
  /*
  sensores.distanceRead();
  Serial.print(sensores.dist[0]);
  Serial.print(" ");
  Serial.print(sensores.dist[1]);
  Serial.print(" ");
  Serial.print(sensores.dist[2]);
  Serial.println(" ");
  */ 

  

  

  leds(20);


  //ENCODER COM ULT + MPU + MOTOR OK, SEM DELAY, MAS JUNTO COM OS VL's NÃO FUNCIONA DIREITO
  //Parece que os VLs atrasam a leitura dos outros sensores e o encoder não consegue atualizar





}





