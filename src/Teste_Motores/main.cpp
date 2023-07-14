#include <Arduino.h>
#include <upload.h>
#include <TB6612FNG.h>

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


void setup() {
  Serial.begin(115200);
  upload_OTA("Oi_A822","MchCM3TM");
  upload_OTA("Oi_A822","MchCM3TM");
  motorA.begin();
  motorB.begin();
}

void loop() {
  
  float velocity = 0.5; //varia de -1.0 a +1.0
  int duration = 500; //a delay of ms after setting motor speed. 500ms
  bool stop = false;//Braking after a delay.
  motorA.drive(velocity, duration, stop);
  motorA.drive(-0.5, 500); //ré

  motorB.drive(velocity, duration);
  motorB.drive(-0.5, 500);

  // Full range of motor speed
  for (auto i = 1; i <= 10; i += 1) {
    motorA.drive(0.1 * i, 200, false);
    motorB.drive(0.1 * i, 200, false);
  }
  motorA.brake();
  motorB.brake();
  delay(1000);
}