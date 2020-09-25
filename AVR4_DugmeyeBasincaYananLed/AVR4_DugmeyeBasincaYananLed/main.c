/*
 * AVR4_DugmeyeBasincaYananLed.c
 *
 * Created: 30.7.2019 09:46:35
 * Author : Gökhan Dökmetaş
 */ 

#include <avr/io.h>


int main(void)
{
    DDRD |= (1<<4); // PD4 ÇIKIŞ
	DDRD &=~(1<<3); // PD3 GİRİŞ
	PORTD |= (1<<3); //PD3 PULL UP
    while (1) 
    {
	  if(!(PIND & (1<<3)))
	  PORTD |= (1<<4);
	  else
	  PORTD &=~(1<<4);
    }
}

