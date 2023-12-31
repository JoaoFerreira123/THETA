#include <Arduino.h>
#include <NewPing.h>


#define TRIGGER_PIN 18
#define ECHO_PIN 19
#define MAX_DISTANCE 200


NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); 

int getValueUltrassonic(int time_delay){
    unsigned int distance = sonar.ping_cm();
   //Serial.print("  U" + String(distance) + "  ");
   delay(time_delay);
   return(distance);
}
