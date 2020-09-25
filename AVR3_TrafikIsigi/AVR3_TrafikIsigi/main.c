/*
 * AVR3_TrafikIsigi.c
 *
 * Created: 30.7.2019 09:36:06
 * Author : Gökhan Dökmetaş
 */ 

#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>

int main(void)
{
    DDRD = 0xFF;
    while (1) 
    {
	PORTD |= (1<<2); // Birinci Led (Kırmızı)
	_delay_ms(1000);
	PORTD &=~(1<<2); // Led söndür
	PORTD |= (1<<3); // İkinci led
	_delay_ms(600);
	PORTD &=~(1<<3);
	PORTD |=(1<<4);
	_delay_ms(2000);
	PORTD &=~(1<<4);
    }
}

