/*
 * AVR8BinarySayici.c
 *
 * Created: 31.7.2019 12:50:00
 *  Author: Gökhan Dökmetaş
 */ 


#include <avr/io.h>
#define  F_CPU 16000000UL
#include <util/delay.h>

int main(void)
{
	DDRD = 0xFF;
	PORTD = 0x00;
	while (1)
	{
		PORTD++;
		_delay_ms(100);
	}
}
