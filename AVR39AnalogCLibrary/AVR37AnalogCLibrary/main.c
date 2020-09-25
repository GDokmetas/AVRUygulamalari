/*
 * AVR37AnalogCLibrary.c
 *
 * Created: 15.5.2020 15:30:51
 * Author : GDokmetas
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include "AnalogComparator.h"
int main(void)
{
    ac_int(ENABLE, INT_TOGGLE);
	sei();
	DDRC |= (1<<5);
    while (1) 
    {
    }
}

ISR (ANALOG_COMP_vect)
{
	PORTC ^= (1<<PC5);
}