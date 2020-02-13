/*
 * UART.cpp
 *
 * Created: 12/02/2020 22:08:47
 * Author : emirg
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#define F_CPU 16000000
#define BAUD 9600
#define BRC ((F_CPU/16/BAUD) - 1)

double dutyCycle = .0;

int main(void)
{
	DDRB = 0xFF;
	
	setupADC();
	
	sei();
	
	UBRR0H = (BRC >> 8);
	UBRR0L = BRC;
	
	UCSR0B = (1 << TXEN0); 
	UCSR0C = (1 << UCSZ01) | (1 << UCSZ00);
	
    /* Replace with your application code */
    while (1) 
    {
		UDR0 = 'b';
    }
}

void setupADC()
{
	ADMUX = (1 << REFS0) | (1 << MUX0) | (1<< MUX2) | (1 << ADLAR);
	ADCSRA = (1 << ADEN) | (1 << ADIE) | (1 << ADPS0) | (1 << ADPS1) | (1 << ADPS2);
	DIDR0 = (1 << ADC5D);
	
	startConversion();
}

void startConversion()
{
	ADCSRA |= (1 << ADSC);
}

ISR(ADC_vect)
{
	UDR0 = 'c'; // Each time conversion happens output character 'c' to serial TX
	PORTB = ADCH >> 3; // Output ADC to portB as a whole
	
	startConversion(); // Restart conversion
}