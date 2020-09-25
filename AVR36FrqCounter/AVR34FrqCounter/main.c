/*
 * AVR34FrqCounter.c
 *
 * Created: 14.5.2020 14:26:43
 * Author : GDokmetas
 */ 

#include <avr/io.h>
#include "freq.h"
#include "uart.h"
#define  F_CPU 16000000UL
#include <util/delay.h>
#include <avr/interrupt.h>
#include <stdio.h>
int main(void)
{
    sei();
	uart_init(UART_BAUD_SELECT(9600,F_CPU));
	_delay_ms(10);
	uart_puts("AVR FREKANS OKUYUCU \n \n");
	
    while (1) 
    {
	f_comp = 10;
	char buf [20];
	freq_start(1000);
	while (f_ready == 0)  {}
	
	uint32_t frq = f_freq;
	sprintf(buf,"%lu \n",frq);
	uart_puts(buf);
    }
}

