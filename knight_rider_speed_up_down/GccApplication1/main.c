/*
	Author: Emirhan Gocturk
	Student Number: 460385
*/

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

// Global delay variable
volatile int delay = 100;

// Custom delay function for ease of use
void delay_ms(int n)
{
	while(n--)
	{
		_delay_ms(1);
	}
}

int main(void)
{
	DDRB = 0xFF;  // Set all output PORT B
	
	// To enable rising edge for INT1 on EICRA
	// set 1 for 3rd and 2nd bit/
	// To enable falling edge for INT0 on EICRA
	// set 1 for 1st bit and 0 for 0th bit
	EICRA = 0x0E; 
	
	// Enable external interrupts for INT1 and INT0
	EIMSK = (1 << INT1) | (1 << INT0);
	
	// Enable global external interrupts
	sei();
	
	// Main loop
	while(1)
	{
		// WARNING
		// Directly dealing with output PORTB
		// Hex is used for convenience
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

// Slow down switch
ISR(INT0_vect)
{
	delay += 10;
}

// Speed up switch
ISR(INT1_vect)
{
	if(delay > 10)
		delay -= 10;
}