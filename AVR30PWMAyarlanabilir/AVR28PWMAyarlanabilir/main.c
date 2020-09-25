/*
 * AVR28PWMAyarlanabilir.c
 *
 * Created: 13.5.2020 11:53:27
 * Author : GDokmetas
 */ 


#include <avr/io.h>
#define  F_CPU 16000000UL
#include <util/delay.h>

int main(void)
{
	DDRD |= (1 << PD6);
    OCR0A = 200;
	TCCR0A |= (1 << COM0A1);
	TCCR0A |= (1 << WGM00);
	TCCR0B |= (1 << CS01);
	while (1)
	{
    for (int i = 0 ; i < 256 ; i++)
	{
	TCCR0A = 0;
	TCCR0B = 0;
	OCR0A = i;
	TCCR0A |= (1 << COM0A1);
	TCCR0A |= (1 << WGM00);
	TCCR0B |= (1 << CS01);
	_delay_ms(20);
	
	}
	}
	
}