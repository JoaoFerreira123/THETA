#include <Arduino.h>
#include <NewPing.h>


#define TRIGGER_PIN 33
#define ECHO_PIN 32
#define MAX_DISTANCE 200


NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); 

void setup() {
  Serial.begin(115200); // Starts the serial communication

}

void loop() {
  unsigned int distance = sonar.ping_cm();
   Serial.print(distance);
   Serial.println("cm");
   delay(50);
}