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


