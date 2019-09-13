/*
	Author: Emirhan Gocturk
	Student Number: 460385
*/

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

int delay = 100;

void delay_ms(int n)
{
	while(n--)
	{
		_delay_ms(1);
	}
}

int main(void)
{
	DDRB = 0xFF;
	
	EICRA = 0b00001110;
	EIMSK = (1 << INT1) | (1 << INT0);
	sei();
	
	// Main loop
	while(1)
	{
		
		for(PORTB = 0x01; PORTB != 0x10; PORTB <<= 1)
		{
			delay_ms(delay);
		}
		
		for(PORTB = 0x10; PORTB != 0x01; PORTB >>= 1)
		{
			delay_ms(delay);
		}
	}
	return 0;
}

ISR(INT0_vect)
{
	delay += 10;
}

ISR(INT1_vect)
{
	delay -= 10;
}