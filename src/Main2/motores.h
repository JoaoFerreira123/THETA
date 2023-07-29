#include <Arduino.h>

//Defines MOTORES e inicialização

// Motor A

int PWMA = 32;
int AIN1 = 5;
int AIN2 = 26;

// Motor B

int PWMB = 33;
int BIN1 = 23;
int BIN2 = 25;



   void definitions(){
    pinMode(PWMA, OUTPUT);
    pinMode(PWMB, OUTPUT);
    pinMode(AIN1, OUTPUT);
    pinMode(AIN2, OUTPUT);
    pinMode(BIN1, OUTPUT);
    pinMode(BIN2, OUTPUT);
   }


//PENSAR A NIVEL DO ROBO, NÃO A NIVEL DE CADA MOTOR! QUERO QUE O ROBO VA PRA FRENTE, NÃO SÓ TAL MOTOR.

void frente(int vel, float time){

    digitalWrite(AIN1, HIGH);
    digitalWrite(AIN2, LOW);
    digitalWrite(BIN1, HIGH);
    digitalWrite(BIN2, LOW);

    //Controla as duas velocidades
    //implementar incremento de velocidade
    analogWrite(PWMA, vel);
    analogWrite(PWMB, vel);
}

void tras(int vel, float time){

}

void direita(){
    //vai ser q basicamente vai mudar o digitalWrite,
    //uma roda p cada direção, e as velocidades
}