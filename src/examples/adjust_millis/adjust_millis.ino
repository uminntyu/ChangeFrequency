#include "ChangeFrequency.h"

ChangeFrequency changeFre;

void setup() {
  // put your setup code here, to run once:
 Serial.begin( 9600 );
 changeFre.setPWMFrequency( TIM_0, DIV_1 );
}

void loop() {
  // put your main code here, to run repeatedly:
  unsigned long mill = changeFre.millis();
  
  changeFre.delay( 1000 );
  Serial.println( changeFre.millis() - mill );
}
