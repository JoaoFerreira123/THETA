#include <Arduino.h>

//define the pins and variables
#define encoderA 36
#define encoderB 39 

volatile long StartTimeA = 0;
volatile long CurrentTimeA = 0;
volatile long PulsesA = 0;
int PulseWidthA = 0;

volatile long StartTimeB = 0;
volatile long CurrentTimeB = 0;
volatile long PulsesB = 0;
int PulseWidthB = 0;


void PulseTimerA(){
  //measure the time between interrupts
  CurrentTimeA = micros();
  if (CurrentTimeA > StartTimeA){
    PulsesA = CurrentTimeA - StartTimeA;
    StartTimeA = CurrentTimeA;
  }
}

void PulseTimerB(){
  //measure the time between interrupts
  CurrentTimeB = micros();
  if (CurrentTimeB > StartTimeB){
    PulsesB = CurrentTimeB - StartTimeB;
    StartTimeB = CurrentTimeB;
  }
}


void getValueEncoderA(){
  pinMode(encoderA, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(encoderA),PulseTimerA,CHANGE);
    if (PulsesA < 2000){
    PulseWidthA = PulsesA;
  } 
  //Serial.print("A: ");
  Serial.print("  A" + String(PulseWidthA) + "  ");
  delay(50);
}

void getValueEncoderB(){
  pinMode(encoderB, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(encoderB),PulseTimerB,CHANGE);
  
    if (PulsesB < 2000){
    PulseWidthB = PulsesB;
  } 
  Serial.print("  B" + String(PulseWidthB) + "  ");
  delay(50);
}


