#include <Arduino.h>

//Defines MOTORES e inicialização
#define STDBY 18

//MOTOR A
#define AIN1 5
#define AIN2 26
#define PWMA 32

#define BIN1 23
#define BIN2 25
#define PWMB 33


//PENSAR A NIVEL DO ROBO, NÃO A NIVEL DE CADA MOTOR! QUERO QUE O ROBO VA PRA FRENTE, NÃO SÓ TAL MOTOR.

void frente(int vel, float time){
    pinMode(AIN1, OUTPUT);
    pinMode(AIN2, OUTPUT);
    digitalWrite(AIN1, HIGH);
    digitalWrite(AIN2, LOW);
}
//NAO FUNCIONOU! FAZER TESTES UNITÁRIOS, SEPARADO DO CÓDIGO PRINCIPAL!!!! 


//MUDAR TODO ESSE CODIGO! FAZER NA MÃO!!! NÃO USAR BIBLIOTECA PROS MOTORES, É UM PWM!!!!
//fazer funcoes para
//frente()
//tras()
//parado()
//esquerda()
//direita()

//todas com argumento de: qual motor, velocidade e tempo
//https://dronebotworkshop.com/tb6612fng-h-bridge/
//https://github.com/makersdigest/T06-TB6612FNG-Motor-Controller/blob/master/arduino/tb6612fng/tb6612fng.ino