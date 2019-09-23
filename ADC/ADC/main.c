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
	
	
	//Configure the ADC
	
	//8bits pr 10bits
	//ADMUX |= (1 << ADLAR);
	// Set max voltage
	ADMUX |= (1 << REFS0);
	
	//Prescale the ADC
	ADCSRA |= (1 << ADPS2);
	//Enable ADC feature for AVR
	ADCSRA |= (1 << ADEN);
	
	//Enable interrupts in ADC
	ADCSRA |= (1 << ADIE);
	
	//Enable interrupts
	sei();
	
	//Start first conversion
	ADCSRA |= (1 << ADSC);
	
	while(1)
	{
		
	}
}

//Start the next conversion - ISR
ISR(ADC_vect)
{
	//PORTB |= 1 << PORTB1;
	uint8_t low_bits = ADCL;
	uint16_t ten_bits = ADCH << 8 | low_bits;
	
	
}