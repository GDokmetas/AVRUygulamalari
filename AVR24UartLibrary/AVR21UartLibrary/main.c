/*
 * AVR21UartLibrary.c
 *
 * Created: 11.5.2020 14:09:22
 * Author : GDokmetas
 */ 

#include <avr/io.h>
#define  F_CPU 16000000UL
#include <util/delay.h>
#include <avr/interrupt.h>
#include "uart.h"
int main(void)
{
	sei();
	uart_init(UART_BAUD_SELECT(9600,F_CPU));
	_delay_ms(100);
	uart_puts("UART DENEME PROGRAMI \n");
    while (1) 
    {
		if (uart_available() > 0)
		uart_putc(uart_getc());
    } 
}

