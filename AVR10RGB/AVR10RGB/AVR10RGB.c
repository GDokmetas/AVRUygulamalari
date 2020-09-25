/*
 * AVR10RGB.c
 *
 * Created: 31.7.2019 17:26:36
 *  Author: Gökhan Dökmetaş
 */ 


#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>
int main(void)
{
	DDRD |= ( (1<<0) | (1<<1) | (1<<2) );
	
    while(1)
    {
    PORTD |= (1<<0); // KIRMIZI
	_delay_ms(500);
	PORTD &=~ (1<<0); // KIRMIZI
	PORTD |= (1<<1); // YEŞİL
	_delay_ms(500);
	PORTD &=~ (1<<1); // KIRMIZI
	PORTD |= (1<<2); // MAVİ
	_delay_ms(500);
	PORTD &=~ (1<<2); 
	PORTD = 0;
	
	PORTD |= (1<<2);
	PORTD |= (1<<1);   
	_delay_ms(1000);
	PORTD = 0;
	PORTD |= (1<<2);
	PORTD |= (1<<0);
	_delay_ms(1000);
	PORTD = 0;
	PORTD |= (1<<2);
	PORTD |= (1<<0);
	PORTD |= (1<<1);
	_delay_ms(2000);
	PORTD = 0;
    }
}