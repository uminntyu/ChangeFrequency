#include "ChangeFrequency.h"
#include <Wire.h>

ChangeFrequency changeFre;

#define ADDR 0x04

void setup()
{
  Wire.begin();
  changeFre.setTWIFrequency( TWI_FASTER );
}

void loop()
{
  static int data = 0;
  
  Wire.beginTransmission( ADDR ); 
  Wire.write( data );        
  Wire.endTransmission();
  delay( 1000 );
  
  data++;
}
