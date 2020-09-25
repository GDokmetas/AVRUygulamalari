/*
 * AVR26PWM.c
 *
 * Created: 13.5.2020 00:17:46
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

	}
	
}