/*
 * AVRUygulama_1LedYakma.c
 *
 * Created: 30.7.2019 09:21:45
 * Author : Gökhan Dökmetaş
 */ 

#include <avr/io.h>

int main(void)
{
    DDRD = 0xFF; // D portunun bütün ayakları çıkış
	PORTD = 0xFF; // PORTD AÇIK

    while (1) 
    {
		
    }
}

