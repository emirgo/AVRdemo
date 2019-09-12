/*
	Author: Emirhan Gocturk
	Student Number: 460385
*/

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

volatile int state = 0;

int main(void)
{
	DDRB = 0x1F;
	
	PORTD = (1 << PORTD3);
	EIMSK = (1 << INT1);
	sei();
	
	// Main loop
	while(1)
	{
		if(state)
		{
			for(PORTB = 0x01; PORTB != 0x10; PORTB <<= 1)
			{
				_delay_ms(50);
			}
			
			for(PORTB = 0x10; PORTB != 0x01; PORTB >>= 1)
			{
				_delay_ms(50);
			}
		}
		else
		{
			PORTB &= ~(1 << PORTB0);
		}
	}
	return 0;
}

ISR(INT1_vect)
{
	if(!state)
	{
		state = 1;
	}
	else
	{
		state = 0;
	}
	_delay_ms(5);
}