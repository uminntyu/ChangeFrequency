#include<ChangeFrequency.h>

ChangeFrequency::ChangeFrequency()
{

}

ChangeFrequency::~ChangeFrequency()
{
	setPWMFrequency();
	setTWIFrequency();
}

uint32_t ChangeFrequency::millis( void )
{
	uint32_t tim = millis();
	switch (division) {
	case DIV_1:    return tim >> 6;
	case DIV_8:    return tim >> 3;
	case DIV_256:  return tim << 2;
	case DIV_1024: return tim << 4;
	default:       return tim;
	}
}

void ChangeFrequency::delay( uint32_t tim )
{
	uint32_t end_tim = ChangeFrequency::millis() + tim;
	while (end_tim > ChangeFrequency::millis());
}

void ChangeFrequency::setPWMFrequency( uint8_t timer, uint8_t divisor )
{
	switch (timer)
	{
	case TIM_0:
		TCCR0B = TCCR0B & 0b11111000 | divisor;
		division = divisor;
		break;

	case TIM_1:
		TCCR1B = TCCR1B & 0b11111000 | divisor;
		break;

	case TIM_2:
		TCCR2B = TCCR2B & 0b11111000 | divisor;
		break;
#if defined (__AVR_ATmega1280__) || (__AVR_ATmega2560__) || (__AVR_ATmega32U4__)
	case TIM_3:
		TCCR3B = TCCR3B & 0b11111000 | divisor;
		break;
#if defined (__AVR_ATmega1280__) || (__AVR_ATmega2560__)
	case TIM_4:
		TCCR4B = TCCR4B & 0b11111000 | divisor;
		break;
#endif
#endif

	case TIM_ALL:
		TCCR0B = TCCR0B & 0b11111000 | divisor;
		TCCR1B = TCCR1B & 0b11111000 | divisor;
		TCCR2B = TCCR2B & 0b11111000 | divisor;
#if defined (__AVR_ATmega1280__) || (__AVR_ATmega2560__) || (__AVR_ATmega32U4__)
		TCCR3B = TCCR3B & 0b11111000 | divisor;
#if defined (__AVR_ATmega1280__) || (__AVR_ATmega2560__)
		TCCR4B = TCCR4B & 0b11111000 | divisor;
#endif
#endif
		division = divisor;
		break;

	default:
		break;
	}
}

void ChangeFrequency::setTWIFrequency( uint32_t frq )
{
	if (frq >= 25000 && frq <= 400000) TWBR = ((F_CPU / frq) - 16) / 2;
	else if (frq > 400000) TWBR = 0x0C;
	else TWBR = 0x48;
}
