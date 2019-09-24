/*
 * ADC.c
 *
 * Created: 23/09/2019 18:50:44
 * Author : emirg
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>

int main()
{
	DDRB = 0xFF;
	
	ADMUX |= (1 << REFS0);// VREF
	ADMUX |= (1 << MUX0) | (1 << MUX2); //set ADC 5
	ADMUX |= (1 << ADLAR);
	
	ADCSRA |= (1 << ADEN); //Enable ADC
	ADCSRA |= (1 << ADIE); // Enable Interrupts for ADC
	
	ADCSRA |= (1 << ADPS0) | (1 << ADPS1) | (1 << ADPS2); // Prescaler at 128
	DIDR0 = (1 << ADC5D);
	ADCSRA |= (1 << ADSC); //Start conversion
	
	sei(); // interrupts
	
	while(1)
	{
		
	}
}

//Start the next conversion - ISR
ISR(ADC_vect)
{
	PORTB = ADCH >> 3;
	ADCSRA |= (1 << ADSC); //Start conversion
}