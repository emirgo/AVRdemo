/*
 * Timers.c
 *
 * Created: 16/09/2019 10:05:42
 * Author: Emirhan Gocturk
 * Student Name: 460385
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>

int extraTimer = 0;

int main(void)
{
	DDRB = 0x01; // Set output pin
	
	TCCR1B = (1 << CS11) | (1 << CS10); // Set prescaler to 64
	TCCR1B |= (1 << WGM12); // Set CTC
	
	OCR1A = 2500; // Comparison TOP value
	TIMSK1 = (1 << OCIE1A); // Set OCRA1A to interrupt
	
	sei(); // Enable global interrupts
	
    while (1)
    {
		
    }
}

ISR(TIMER1_COMPA_vect)
{
	extraTimer++;
	if(extraTimer >= 25) // 25 x 0.01s = 0.25s
	{
		PORTB ^= (1 << PORTB0);
		extraTimer = 0; // Reset timer
	}
}