#include <Arduino.h>

// -------------Encoder A pins -----------
const int PinDT_A=36;    // DATA signal
const int PinCLK_A=39;    // CLOCK signal

// Variables to debounce Rotary EncoderA
long TimeOfLastDebounce_A = 0;
int DelayofDebounce_A = 0.01;

// Store previous Pins state
int PreviousCLK_A;   
int PreviousDATA_A;

int displaycounter_A=0; // Store current counter value



// ----------- Encoder B Pins ----------------
const int PinDT_B=34;    // DATA signal
const int PinCLK_B=35;    // CLOCK signal

// Variables to debounce Rotary Encoder
long TimeOfLastDebounce_B = 0;
int DelayofDebounce_B = 0.01;

// Store previous Pins state
int PreviousCLK_B;   
int PreviousDATA_B;

int displaycounter_B=0; // Store current counter value




// Check if Rotary Encoder was moved
void check_rotaryA() {

 if ((PreviousCLK_A == 0) && (PreviousDATA_A == 1)) {
    if ((digitalRead(PinCLK_A) == 1) && (digitalRead(PinDT_A) == 0)) {
      displaycounter_A++;
      //Serial.println(displaycounter);
    }
    if ((digitalRead(PinCLK_A) == 1) && (digitalRead(PinDT_A) == 1)) {
      displaycounter_A--;
      //Serial.println(displaycounter);
    }
  }

if ((PreviousCLK_A == 1) && (PreviousDATA_A == 0)) {
    if ((digitalRead(PinCLK_A) == 0) && (digitalRead(PinDT_A) == 1)) {
      displaycounter_A++;
      //Serial.println(displaycounter);
    }
    if ((digitalRead(PinCLK_A) == 0) && (digitalRead(PinDT_A) == 0)) {
      displaycounter_A--;
      //Serial.println(displaycounter);
    }
  }

if ((PreviousCLK_A == 1) && (PreviousDATA_A == 1)) {
    if ((digitalRead(PinCLK_A) == 0) && (digitalRead(PinDT_A) == 1)) {
      displaycounter_A++;
      //Serial.println(displaycounter);
    }
    if ((digitalRead(PinCLK_A) == 0) && (digitalRead(PinDT_A) == 0)) {
      displaycounter_A--;
      //Serial.println(displaycounter_A);
    }
  }  

if ((PreviousCLK_A == 0) && (PreviousDATA_A == 0)) {
    if ((digitalRead(PinCLK_A) == 1) && (digitalRead(PinDT_A) == 0)) {
      displaycounter_A++;
      //Serial.println(displaycounter_A);
    }
    if ((digitalRead(PinCLK_A) == 1) && (digitalRead(PinDT_A) == 1)) {
      displaycounter_A--;
      //Serial.println(displaycounter_A);
    }
  }            
 }

int encoderA(){
   // If enough time has passed check the rotary encoder
  if ((millis() - TimeOfLastDebounce_A) > DelayofDebounce_A) {
    
    check_rotaryA();  // Rotary Encoder check routine below
    
    PreviousCLK_A=digitalRead(PinCLK_A);
    PreviousDATA_A=digitalRead(PinDT_A);
    
    TimeOfLastDebounce_A=millis();  // Set variable to current millis() timer
  }
  return(displaycounter_A);
}


// Check if Rotary Encoder B was moved
void check_rotaryB() {

 if ((PreviousCLK_B == 0) && (PreviousDATA_B == 1)) {
    if ((digitalRead(PinCLK_B) == 1) && (digitalRead(PinDT_B) == 0)) {
      displaycounter_B++;
      //Serial.println(displaycounter);
    }
    if ((digitalRead(PinCLK_B) == 1) && (digitalRead(PinDT_B) == 1)) {
      displaycounter_B--;
      //Serial.println(displaycounter);
    }
  }

if ((PreviousCLK_B == 1) && (PreviousDATA_B == 0)) {
    if ((digitalRead(PinCLK_B) == 0) && (digitalRead(PinDT_B) == 1)) {
      displaycounter_B++;
      //Serial.println(displaycounter);
    }
    if ((digitalRead(PinCLK_B) == 0) && (digitalRead(PinDT_B) == 0)) {
      displaycounter_B--;
      //Serial.println(displaycounter);
    }
  }

if ((PreviousCLK_B == 1) && (PreviousDATA_B == 1)) {
    if ((digitalRead(PinCLK_B) == 0) && (digitalRead(PinDT_B) == 1)) {
      displaycounter_B++;
      //Serial.println(displaycounter);
    }
    if ((digitalRead(PinCLK_B) == 0) && (digitalRead(PinDT_B) == 0)) {
      displaycounter_B--;
      //Serial.println(displaycounter_B);
    }
  }  

if ((PreviousCLK_B == 0) && (PreviousDATA_B == 0)) {
    if ((digitalRead(PinCLK_B) == 1) && (digitalRead(PinDT_B) == 0)) {
      displaycounter_B++;
      //Serial.println(displaycounter_B);
    }
    if ((digitalRead(PinCLK_B) == 1) && (digitalRead(PinDT_B) == 1)) {
      displaycounter_B--;
      //Serial.println(displaycounter_B);
    }
  }            
 }

int encoderB(){
   // If enough time has passed check the rotary encoder
  if ((millis() - TimeOfLastDebounce_B) > DelayofDebounce_B) {
    
    check_rotaryB();  // Rotary Encoder check routine below
    
    PreviousCLK_B=digitalRead(PinCLK_B);
    PreviousDATA_B=digitalRead(PinDT_B);
    
    TimeOfLastDebounce_B=millis();  // Set variable to current millis() timer
  }
  return(displaycounter_B);
}