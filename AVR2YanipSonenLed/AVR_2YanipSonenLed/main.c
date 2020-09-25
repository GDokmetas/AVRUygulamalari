/*
 * AVR_2YanipSonenLed.c
 *
 * Created: 30.7.2019 09:29:07
 * Author : Gökhan Dökmetaş
 */ 

#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>
int main(void)
{
    DDRD = 0xFF; // PORTD ÇIKIŞ 
    while (1) 
    {
		PORTD = 0xFF;
		_delay_ms(1000);
		PORTD = 0x00;
		_delay_ms(1000);
    }
}

