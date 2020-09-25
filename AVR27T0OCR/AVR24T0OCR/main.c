/*
 * AVR22T0Basic.c
 *
 * Created: 12.5.2020 23:06:45
 * Author : GDokmetas
 */ 

#include <avr/io.h>
#define F_CPU 16000000UL
#include <avr/interrupt.h>

int main(void)
{
    DDRC |= (1<<PC5);
    TCCR0B |= (1<<CS00);
	TCCR0B |= (1<<CS02);
	TCCR0A |= (1<<WGM01); // CTC MOD
	OCR0A = 155;
	
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
