/*
 * AVR29T0IC.c
 *
 * Created: 13.5.2020 12:22:20
 * Author : GDokmetas
 */ 

#include <avr/io.h>
#define F_CPU 16000000UL
#include <avr/interrupt.h>

int main(void)
{
	DDRC |= (1<<PC5);
	DDRD &= ~(1<<PORTD4);
	TCCR0B |= (1<<CS01);
	TCCR0B |= (1<<CS02);
	TCCR0A |= (1<<WGM01); // CTC MOD
	OCR0A = 5;
	
	TIMSK0 |= (1<<OCIE0A);
	sei();
	while (1)
	{
	}
}

ISR (TIMER0_COMPA_vect)
{
	PORTC ^= (1<<PC5);
}

