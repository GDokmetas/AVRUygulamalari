/*
 * AVR12PortPerformans.c
 *
 * Created: 1.8.2019 19:33:49
 *  Author: Gökhan Dökmetaş
 */ 


#include <avr/io.h>

int main(void)
{
	DDRD = 0xFF;
    while(1)
    {
    PORTD = 0xFF;
	PORTD = 0x00;
    }
}