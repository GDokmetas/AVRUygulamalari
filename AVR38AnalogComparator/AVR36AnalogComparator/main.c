/*
 * AVR36AnalogComparator.c
 *
 * Created: 15.5.2020 15:10:43
 * Author : GDokmetas
 */ 

#include <avr/io.h>


int main(void)
{ 
    DDRC |= (1<<PC5);
    while (1) 
    {
		if(ACSR & (1<<ACO))
		PORTC |= (1<<PC5);
		else
		PORTC &=~(1<<PC5);
    }
}

