#include <Arduino.h>
#include <TB6612FNG.h>

//Defines MOTORES e inicialização
#define STDBY 32

//MOTOR A
#define AIN1 18
#define AIN2 16
#define PWMA 17
Tb6612fng motorA(STDBY, AIN1, AIN2, PWMA);

#define BIN1 23
#define BIN2 25
#define PWMB 33
Tb6612fng motorB(STDBY, BIN1, BIN2, PWMB);



//Variaveis Encoder
const int encoderPin = 34;
unsigned long pulseWidth = 0;
unsigned long lastTime = 0;
int encoderCount = 0;

void setup() {
  Serial.begin(115200);
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