/*
 * AVR50TWIMaster.c
 *
 * Created: 28.6.2020 06:55:09
 * Author : GDokmetas
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include "TWI_Master.h"
#define F_CPU 16000000UL
#include <util/delay.h>
int main(void)
{
    TWI_Master_Initialise();
	sei();
    while (1) 
    {
	unsigned char buf[2];
	buf[0] = 0x3F << 1;
	buf[1] = 0xFF;
	TWI_Start_Transceiver_With_Data(buf, 2);
	_delay_ms(500);
	buf[1] = 0x00;
	TWI_Start_Transceiver_With_Data(buf, 2);
	_delay_ms(500);
    }
}

