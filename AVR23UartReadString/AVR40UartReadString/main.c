/*
 * AVR40UARTReadString.c
 *
 * Created: 16.5.2020 01:40:50
 * Author : GDokmetas
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#define F_CPU 16000000UL
#include <util/delay.h>
#include "uart.h"
#include <string.h>
int main(void)
{
    sei();
    uart_init(UART_BAUD_SELECT(9600,F_CPU));
    _delay_ms(100);
    uart_puts("UART STRING OKUMA \n");
    
    while (1) 
    {
	if (uart_available() > 0)
		{
		int i = 0;
	    char buf [20];
		while(1)
			{
			
			buf[i] = uart_getc();
			if (buf[i] == '\n')
			break;
			if (buf[i] == '\0')
			break;
			if (buf[i] == '\r')
			break;
			i++;
			if (i>19)
			i = 0;
			}
		uart_puts(buf);
		}
	
	}
	
}

