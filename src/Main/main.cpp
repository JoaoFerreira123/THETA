#include <Arduino.h>
#include <Wire.h>


//Variaveis Encoder
const int encoderPin = 34;
unsigned long pulseWidth = 0;
unsigned long lastTime = 0;
int encoderCount = 0;

void setup() {
  Serial.begin(19200);
  pinMode(encoderPin, INPUT_PULLUP);
}

void loop() {
  // Lê o pulso do encoder
  pulseWidth = pulseIn(encoderPin, HIGH);

  // Calcula a velocidade do encoder
  unsigned long currentTime = micros();
  unsigned long pulsePeriod = currentTime - lastTime;
  lastTime = currentTime;
  int encoderSpeed = 1000000 / pulsePeriod;

  // Incrementa ou decrementa o contador do encoder com base na direção
  if (pulseWidth > 1500) {
    encoderCount++;
  } else if (pulseWidth < 1500) {
    encoderCount--;
  }

  Serial.println(pulseWidth);
  delay(10);
}