#include <Arduino.h>
#include "ChangeFrequency.h"

ChangeFrequency changeFre;

void setup() {
  // put your setup code here, to run once:
  changeFre.setPWMFrequency( TIM_ALL , DIV_1 );
}

void loop() {
  // put your main code here, to run repeatedly:
  static byte val = 0;
  
  for ( int pin = 2; pin <= 13; pin++ ) analogWrite( pin, val );
  changeFre.delay( 500 );

  val++;
}
