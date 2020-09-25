/*
 * AVR39PCINT.c
 *
 * Created: 15.5.2020 17:16:56
 * Author : GDokmetas
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>

int main(void)
{
    PCICR |= ((1<<PCIE2)|(1<<PCIE1));
	PCMSK2 |= (1<<PCINT20);
	PCMSK1 |= (1<<PCINT8);
	PCMSK0 |= (1<<PCINT2);
	DDRC |= ((1<<PC5) | (1<<PC4));
	sei();
    while (1) 
    {
		
    }
}

ISR (PCINT1_vect)
{
	PORTC ^= (1<<PC5);
}

ISR (PCINT2_vect)
{
	PORTC ^= (1<<PC4);
}

