
#pragma once

#include <Arduino.h>

#define F_TWI      100000
#define TWI_FASTER 400000
#define TWI_SLOWER 25000

#define STOP       0x00
#define DIV_1      0x01
#define DIV_8      0x02
#define DIV_64     0x03
#define DIV_256    0x04
#define DIV_1024   0x05

#define TIM_0     1
#define TIM_1     2
#define TIM_2     3
#define TIM_3     4
#define TIM_4     5
#define TIM_ALL   6

class ChangeFrequency
{
  public:
    ChangeFrequency();
    ~ChangeFrequency();
    uint32_t millis( void );
    void delay( uint32_t tim );
    void setPWMFrequency( uint8_t timer = TIM_ALL, uint8_t divisor = DIV_64 );
    void setTWIFrequency( uint32_t frq = F_TWI );

  private:
    uint8_t division = DIV_64;
};
