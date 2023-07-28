#include <Arduino.h>
#include <NewPing.h>


#define TRIGGER_PIN 33
#define ECHO_PIN 32
#define MAX_DISTANCE 200


NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); 

void getValueUltrassonic(int time_delay){
    unsigned int distance = sonar.ping_cm();
   Serial.print("  U" + String(distance) + "  ");
   delay(time_delay);
}
