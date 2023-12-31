#include <VL53L0X.h>

//I2c PINS 

#define SCL_SDIST 22
#define SDA_SDIST 21


//X SHUT PINS 
//Tem que ser PINOS ADC! 
#define SDIST_1 32
#define SDIST_2 33
#define SDIST_3 25

#define N_SENSOR 3 

int X_SHUT[N_SENSOR] = { SDIST_1, SDIST_2, SDIST_3} ;

class VL53_sensors
{
private:
    /* data */
public:
    int number_sensor = 3; // change this value 
    int x_shut_pins[3] = { SDIST_1, SDIST_2, SDIST_3} ; 
    int dist[3];

    VL53L0X sensor[3];
    
    void sensorsInit();
    void distanceRead();
    void printDistances();
};



void VL53_sensors::sensorsInit() {

    //Iniciando o endereçamento dos sensores
    Wire.begin();

    for (uint8_t i = 0; i < number_sensor; i++){
      pinMode(x_shut_pins[i], OUTPUT);
      digitalWrite(x_shut_pins[i], LOW);


    }

    for (uint8_t i = 0; i < number_sensor; i++){
      pinMode(x_shut_pins[i], INPUT);
      sensor[i].init(true);
      sensor[i].setAddress((uint8_t)0x21 + i); //endereço do sensor 1
      sensor[i].setTimeout(40);
    }
    
}

void VL53_sensors::distanceRead() {

    for (uint8_t i = 0; i < number_sensor; i++){
       dist[i] = sensor[i].readRangeSingleMillimeters();
     
    }
     
   
}

void VL53_sensors::printDistances() {


  for (uint8_t i = 0; i < number_sensor; i++){

       Serial.print(" ");
       Serial.print(String(i));
       Serial.print(" ");
       Serial.print(dist[i]);

      Serial.println("\t\t");
  }

}
