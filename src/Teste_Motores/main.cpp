#include <Arduino.h>

/*
  TB6612FNG H-Bridge Demo
  TB6612-Demo.ino
  Demonstrates use of TB6612FNG H-Bridge Motor Controller
  Drives two DC Motors

  DroneBot Workshop 2019
  https://dronebotworkshop.com
*/

// Motor A

int pwmA = 32;
int in1A = 5;
int in2A = 26;

// Motor B

int pwmB = 33;
int in1B = 23;
int in2B = 25;



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

  
}