#include <Arduino.h>

#define ANALOG_IN 0
#define Ref_signal_490Hz 10
#define Ref_signal_980Hz 5

//
// auf GPIO 10 ein PWM Signal mit 490 Hz
// auf GPIO 5 ein PWM Signal mit 980 Hz
//
// Pulsbreite: 100% = 255
// d. h. bei 50 ist 1/5 high und 4/5 low
// und bei 127 1/2 und 1/2


void setup() {
  Serial.begin(115200); 
  //Serial.begin(115200); 
  // analogWrite( GPIO, Pulsbreite von 0= immer aus  bis 255= immer an)
  analogWrite (Ref_signal_490Hz,50);
  analogWrite (Ref_signal_980Hz,127);
}

void loop() {
  int val = analogRead(ANALOG_IN);                                              
  Serial.write( 0xff );                                                         
  Serial.write( (val >> 8) & 0xff );                                            
  Serial.write( val & 0xff );
}