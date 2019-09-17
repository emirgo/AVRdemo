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
	DDRB = 0x01;
	TCCR1B = (1 << CS12) | (1 << CS10) | (1 << WGM12); //Setting prescaler 1024
	OCR1A = 195;
	TIMSK1 = (1 << OCIE1A);
	
	sei();
	
    while (1)
    {
		
    }
}

ISR(TIMER1_COMPA_vect)
{
	extraTimer++;
	if(extraTimer >= 25)
	{
		PORTB ^= (1 << PORTB0);
		extraTimer = 0;
	}
}