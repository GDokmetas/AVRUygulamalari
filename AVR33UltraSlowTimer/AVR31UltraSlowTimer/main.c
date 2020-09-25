/*
 * AVR31UltraSlowTimer.c
 *
 * Created: 13.5.2020 16:03:27
 * Author : GDokmetas
 */ 

#include <avr/io.h>
#define F_CPU 16000000UL
#include <avr/interrupt.h>

int main(void)
{
	DDRD &=~(1<<PORTD5);
	DDRD |=(1<<PORTD6);
	DDRB |=(1<<PORTB1);
	
	TCCR0B |= (1<<CS00);
	TCCR0B |= (1<<CS02);
	TCCR0A |= (1<<WGM01); // CTC MOD
	TCCR0A |= (1<<COM0A0);
	OCR0A = 255;
	
	TCCR1A |= (1<<COM1A0);
	TCCR1B |= (1<<WGM12); //CTC
	TCCR1B |= ((1<<CS10) | (1<<CS11) |(1<<CS12) ); //external input
	OCR1A = 1;
	

	while (1)
	{
	}
}
