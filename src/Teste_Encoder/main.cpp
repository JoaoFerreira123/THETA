// Inclua as bibliotecas necessárias
#include <Arduino.h>

// Define os pinos utilizados para a leitura do encoder
const int encoderPin = 34;

// Variáveis globais
unsigned long pulseWidth = 0;
unsigned long lastTime = 0;
int encoderCount = 0;

void setup() {
  // Inicializa a comunicação serial
  Serial.begin(19200);

  // Define o pino do encoder como entrada
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

  // Exibe os resultados no Monitor Serial
  //Serial.print("Pulso: ");
  Serial.println(pulseWidth);
  //Serial.print(", Velocidade: ");
  //Serial.print(encoderSpeed);
  //Serial.print(", Contagem: ");
  //Serial.println(encoderCount);
  
  // Aguarda um breve intervalo antes da próxima leitura
  delay(10);
}