/*
 * AVR25T0Freq.c
 *
 * Created: 12.5.2020 23:49:27
 * Author : GDokmetas
 */ 


#include <avr/io.h>
#define F_CPU 16000000UL
#include <avr/interrupt.h>
#include <util/delay.h>
int main(void)
{
    DDRD |= (1<<PD6);
    TCCR0B |= (1<<CS00);
	TCCR0B |= (1<<CS02);
	TCCR0A |= (1<<WGM01); // CTC MOD
	TCCR0A |= (1<<COM0A0);
    while (1) 
    {
	for (int i=0; i<256; i++)
	{
	OCR0A = i;
	_delay_ms(20);
	}
	
    }
}

