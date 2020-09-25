/*
 * AVR6Karasimsek.c
 *
 * Created: 31.7.2019 12:22:04
 * Author : Gökhan Dökmetaş
 */ 


// KARAŞİMŞEK

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	
DDRD = 0xFF;                    
while (1) {                      
	
	for (PORTD = 0x01; PORTD != 0; PORTD <<= 1)
	_delay_ms(50);           
	
	for (PORTD = 0x80; PORTD != 0; PORTD >>= 1)
	_delay_ms(50);
}
}