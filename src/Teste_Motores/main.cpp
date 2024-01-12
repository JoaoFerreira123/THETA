#include <Arduino.h>
#include <WiFi.h>

/*
  TB6612FNG H-Bridge Demo
  TB6612-Demo.ino
  Demonstrates use of TB6612FNG H-Bridge Motor Controller
  Drives two DC Motors

  DroneBot Workshop 2019
  https://dronebotworkshop.com
*/


// Motor A

int PWMA = 4; 
int AIN1 = 12;
int AIN2 = 13;

// Motor B

int PWMB = 26; 
int BIN1 = 14; 
int BIN2 = 27;




// Motor Speed Values - Start at zero

int MotorSpeed1 = 0;
int MotorSpeed2 = 0; 

void setup()

{

  // Set all the motor control pins to outputs

    pinMode(PWMA, OUTPUT);
    pinMode(PWMB, OUTPUT);
    pinMode(AIN1, OUTPUT);
    pinMode(AIN2, OUTPUT);
    pinMode(BIN1, OUTPUT);
    pinMode(BIN2, OUTPUT);
   
}

void loop() {
  //PRA FRENTE
  // Set Theta forward

  digitalWrite(AIN1, LOW);
  digitalWrite(AIN2, HIGH);

  digitalWrite(BIN1, HIGH);
  digitalWrite(BIN2, LOW);

  analogWrite(PWMA, 50);
  analogWrite(PWMB, 50);
  
  delay(2000);
  /*
    Set the motor speeds
    for(int i = 0; i<255; i+=5){
    analogWrite(PWMA, i);
    analogWrite(PWMB, i);
    delay(100);
  }
  */ 
  




  //PRA TRÁS
  // Set Motor Theta backward

  digitalWrite(AIN1, HIGH);
  digitalWrite(AIN2, LOW);

  digitalWrite(BIN1, LOW);
  digitalWrite(BIN2, HIGH);

  analogWrite(PWMA, 50);
  analogWrite(PWMB, 50);
  delay(2000);
  
  /*
    Set the motor speeds
    for(int i = 255; i>0; i-=5){
      analogWrite(PWMA, i);
      analogWrite(PWMB, i);
    delay(100);
  }
  */ 
  



}