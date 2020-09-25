/*
 * AVR38EXINT.c
 *
 * Created: 15.5.2020 16:18:51
 * Author : GDokmetas
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>

int main(void)
{
    EIMSK |= ((1<<INT1)|(1<<INT0));
	DDRC  |= ((1<<PC5)|(1<<PC4));
	sei();
    while (1) 
    {

    }
}

ISR (INT0_vect)
{
	PORTC |= (1<<PC5);
}

ISR (INT1_vect)
{
	PORTC |= (1<<PC4);
}

