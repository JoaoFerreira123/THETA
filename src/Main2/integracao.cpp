#include <Arduino.h>
#include "motores.h"
#include "encoders.h"
#include "ultrassonico.h"
#include "mpu.h"


void setup() {
  Serial.begin(115200);
  //MPUstarted();
}

void loop() {

  //getValueEncoderA();
  //getValueEncoderB();
  //getValueUltrassonic();
  //getAngle(); //AINDA NÃO CONSEGUI EM ÂNGULO, SOMENTE RAD/S?? E QDO CONVERTO FICA ESTRANHO
  //NÃO CONSEGUI TER UMA LEITURA DESCENTE!
  //getValueUltrassonic(100); OK, funciona. MAS USA PULSEIN -> Mudar código

}