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

int pwmA = 4;
int in1A = 12;
int in2A = 13;

// Motor B

int pwmB = 14;
int in1B = 26;
int in2B = 27;



// Motor Speed Values - Start at zero

int MotorSpeed1 = 0;
int MotorSpeed2 = 0; 

void setup()

{

  // Set all the motor control pins to outputs

  pinMode(pwmA, OUTPUT);
  pinMode(pwmB, OUTPUT);
  pinMode(in1A, OUTPUT);
  pinMode(in2A, OUTPUT);
  pinMode(in1B, OUTPUT);
  pinMode(in2B, OUTPUT);
   
}

void loop() {
  //PRA FRENTE
  // Set Motor A forward

  digitalWrite(in1A, HIGH);
  digitalWrite(in2A, LOW);

 // Set Motor B forward

  digitalWrite(in1B, HIGH);
  digitalWrite(in2B, LOW);
  
    
  // Set the motor speeds
  
  for(int i = 0; i<255; i+=5){
    analogWrite(pwmA, i);
    analogWrite(pwmB, i);
    delay(100);
  }


  //delay(1000);
  //PRA TRÁS
  // Set Motor A backward

  digitalWrite(in1A, LOW);
  digitalWrite(in2A, HIGH);

 // Set Motor B backward

  digitalWrite(in1B, LOW);
  digitalWrite(in2B, HIGH);

    // Set the motor speeds
  
  for(int i = 255; i>0; i-=5){
    analogWrite(pwmA, i);
    analogWrite(pwmB, i);
    delay(100);
  }


}