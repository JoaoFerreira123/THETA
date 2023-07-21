#include <Arduino.h>
#include "motores.h"
#include "encoders.h"


void setup() {
  Serial.begin(115200);
  motorA.begin();
  motorB.begin();
}

void loop() {

  getValueEncoderA();
  getValueEncoderB();
  

}