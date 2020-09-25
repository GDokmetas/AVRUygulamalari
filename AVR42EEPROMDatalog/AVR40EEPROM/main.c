/*
 * AVR40EEPROM.c
 *
 * Created: 16.5.2020 17:16:18
 * Author : GDokmetas
 */ 

#include <avr/io.h>
#include "adc.h"
#define  F_CPU 16000000UL
#include <util/delay.h>
void datalog(void);
uint16_t address = 0;
int main(void)
{
    adc_init();
	DDRC |=(1<<PC4);
    while (1) 
    {
		if(!(PINC & (1<<PC3)))
		datalog();
    }
}

void datalog()
{
	PORTC |= (1<<PC4);
	while (PINC & (1<<PC3)); 
    _delay_ms(50);
	uint8_t veri = adc_read_map(0, 0, 255);
	while(EECR & (1<<EEPE))
	;
	/* Adres ve Veri yazmaçlarýný ayarla*/
	EEAR = address;
	EEDR = veri;
	/*EEMPE bitini bir yap */
	EECR |= (1<<EEMPE);
	/* EEPE bitini bir yaparak yazmaya baþlat.*/
	EECR |= (1<<EEPE);
	address++;
	while(EECR & (1<<EEPE))
	;
	/* Adres ve Veri yazmaçlarýný ayarla*/
	EEAR = address;
	EEDR = 0;
	/*EEMPE bitini bir yap */
	EECR |= (1<<EEMPE);
	/* EEPE bitini bir yaparak yazmaya baþlat.*/
	EECR |= (1<<EEPE);
	PORTC &= ~(1<<PC4);
}