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
	TIMSK0 |= (1<<TOIE0);
	sei();
	// osiloskop ve hesap makinesinden ölçülecek. 
    while (1) 
    {
    }
}

ISR (TIMER0_OVF_vect)
{
	PORTC ^= (1<<PC5);
}



