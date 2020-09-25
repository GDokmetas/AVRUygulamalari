/*
 * AVR35ICR.c
 *
 * Created: 14.5.2020 15:51:23
 * Author : GDokmetas
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#define  F_CPU 16000000UL
#include <util/delay.h>
#include "uart.h"
#include <stdio.h>
volatile unsigned char ov_counter; 
volatile unsigned int starting_edge, ending_edge; 
volatile unsigned long clocks; 
int main(void)
{
	DDRB &= ~(1<<PORTB0);
    sei();
	uart_init(UART_BAUD_SELECT(9600,F_CPU));
	_delay_ms(100);
	uart_puts("INPUT CAPTURE DENEME PROGRAMI \n");
	TCCR1B &= ~(1<<ICES1);
	TCCR1B |= (1<<CS10);
	TCCR1B |= (1<<CS01);
	TIMSK1 |= ((1<<ICIE1) | (1<<TOIE1));
    while (1) 
    {
    	char buffer[10];
    	sprintf(buffer, "%lu \n",clocks);
    	uart_puts(buffer);
    }
}

ISR (TIMER1_OVF_vect)
{
	++ov_counter;
}

ISR (TIMER1_CAPT_vect)
{
	ending_edge = 256*ICR1H + ICR1L; 
	clocks = (unsigned long)ending_edge + ((unsigned long)ov_counter * 65536) - (unsigned long)starting_edge;
	ov_counter = 0;
	starting_edge = ending_edge;
}
