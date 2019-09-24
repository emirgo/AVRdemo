/*
 * Timers.c
 *
 * Created: 16/09/2019 10:05:42
 * Author: Emirhan Gocturk
 * Student Name: 460385
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>

volatile int extraTimer = 0;
volatile int extraTimer8bit = 0;

int main(void)
{
	DDRB = 0xFF; // Set output pin
	
	// 16-bit timer
	TCCR1B = (1 << CS11) | (1 << CS10); // Set prescaler to 64
	TCCR1B |= (1 << WGM12); // Set CTC
	
	OCR1A = 2500; // Comparison TOP value
	TIMSK1 = (1 << OCIE1A); // Set OCRA1A to interrupt
	
	// 8-bit timer
	TCCR0B |= (1 << WGM01);
	TCCR0B |= (1 << CS01);
	OCR0A = 200;
	TIMSK0 = (1 << OCIE1A);
	
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

ISR(TIMER0_COMPA_vect)
{
	extraTimer8bit++;
	if(extraTimer8bit >= 2500)
	{
		PORTB ^= (1 << PORTB1);
		extraTimer8bit = 0; // Reset timer
	}
	
}