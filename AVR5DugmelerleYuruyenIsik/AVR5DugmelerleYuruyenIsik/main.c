/*
 * AVR5DugmelerleYuruyenIsik.c
 *
 * Created: 31.7.2019 12:16:55
 * Author : Gökhan Dökmetaş
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	
	DDRD = 0xFF;
	DDRB &=~ ((1<<0) | (1<<1));
	PORTB |= ((1<<0) | (1<<1));
	PORTD |= (1<<PD0);
	
	while (1)
	{
		if(bit_is_clear(PINB,0))
		{
			PORTD<<=1;
			_delay_ms(250);
		}
		
		
		if(bit_is_clear(PINB,1))
		{
			PORTD>>=1;
			_delay_ms(250);
		}
	}
}