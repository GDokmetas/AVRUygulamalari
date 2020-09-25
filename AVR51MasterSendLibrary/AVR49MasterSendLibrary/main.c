/*
 * AVR49MasterSendLibrary.c
 *
 * Created: 26.6.2020 06:54:26
 * Author : GDokmetas
 */ 

#include <avr/io.h>
#include "i2cmaster.h"
#define F_CPU 16000000UL
#include <util/delay.h>
int main(void)
{
    i2c_init();
	
    while (1) 
    {
		i2c_start(0x3F << 1);
		i2c_write(0xFF);
		_delay_ms(500);
		i2c_write(0x00);
		_delay_ms(500);
		i2c_stop();
		
    }
}

