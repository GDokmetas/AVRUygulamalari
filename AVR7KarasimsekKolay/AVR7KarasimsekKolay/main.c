/*
 * AVR7KarasimsekKolay.c
 *
 * Created: 31.7.2019 12:33:32
 * Author : Gökhan Dökmetaş
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	
	DDRD = 0xFF;
	int bekleme = 150;
	while (1)
	{
		
		for(int i = 0; i < 7; i++)
		{
			PORTD |=_BV(i);
			_delay_ms(bekleme);
			PORTD &=~_BV(i);
		}
		
		for(int i = 7; i > 0; i--)
		{
			PORTD |=_BV(i);
			_delay_ms(bekleme);
			PORTD &=~_BV(i);
		}
	}
}