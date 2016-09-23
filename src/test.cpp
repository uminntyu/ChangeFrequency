#include <Arduino.h>
#include "ChangeFrequency.h"

ChangeFrequency changeFre;

void setup() {
  // put your setup code here, to run once:
  changeFre.setPWMFrequency( TIM_ALL , DIV_8 );
  analogWrite( 13, 127 );
}

void loop()
{

}
    
