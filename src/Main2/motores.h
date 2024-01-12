#include <Arduino.h>

//Defines MOTORES e inicialização

// Motor A

int PWMA = 4; 
int AIN1 = 12;
int AIN2 = 13;

// Motor B

int PWMB = 26; 
int BIN1 = 14; 
int BIN2 = 27;



void frente(int vel){

    digitalWrite(AIN1, LOW);
    digitalWrite(AIN2, HIGH);
    digitalWrite(BIN1, HIGH);
    digitalWrite(BIN2, LOW);

    //Controla as duas velocidades
    //implementar incremento de velocidade
    analogWrite(PWMA, vel);
    analogWrite(PWMB, vel);
    
}

void tras(int vel){
    digitalWrite(AIN1, HIGH);
    digitalWrite(AIN2, LOW);
    digitalWrite(BIN1, LOW);
    digitalWrite(BIN2, HIGH);

    //Controla as duas velocidades
    //implementar incremento de velocidade
    analogWrite(PWMA, vel);
    analogWrite(PWMB, vel);
}

void direita(int vel){
    //vai ser q basicamente vai mudar o digitalWrite,
    //uma roda p cada direção, e as velocidades
    digitalWrite(AIN1, HIGH);
    digitalWrite(AIN2, LOW);
    digitalWrite(BIN1, HIGH);
    digitalWrite(BIN2, LOW);

    //Controla as duas velocidades
    //implementar incremento de velocidade
    analogWrite(PWMA, vel);
    analogWrite(PWMB, vel);
    
}

void esquerda(int vel){
    //vai ser q basicamente vai mudar o digitalWrite,
    //uma roda p cada direção, e as velocidades
    digitalWrite(AIN1, LOW);
    digitalWrite(AIN2, HIGH);
    digitalWrite(BIN1, LOW);
    digitalWrite(BIN2, HIGH);

    //Controla as duas velocidades
    //implementar incremento de velocidade
    analogWrite(PWMA, vel);
    analogWrite(PWMB, vel);


}

void stop(){
    digitalWrite(AIN1, LOW);
    digitalWrite(AIN2, LOW);
    digitalWrite(BIN1, LOW);
    digitalWrite(BIN2, LOW);

    analogWrite(PWMA, 0);
    analogWrite(PWMB, 0);
}