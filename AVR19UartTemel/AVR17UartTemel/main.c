/*
 * AVR17UartTemel.c
 *
 * Created: 10.5.2020 13:11:26
 * Author : GDokmetas
 */ 

#include <avr/io.h>
#define F_CPU 16000000UL
#define BAUD 9600                                   // Baud Oranýný Tanýmlýyoruz
#define BAUDRATE ((F_CPU)/(BAUD*16UL)-1)            // UBRR için baud verisini ayarlýyoruz
void uart_basla(uint32_t baud);
void uart_gonder(uint8_t data);
uint8_t uart_oku();
int main(void)
{
    uart_basla(9600);
    while (1) 
    {
		uart_gonder('a');
    }
}



void uart_basla(uint32_t baud){
	uint16_t baudRate=F_CPU/baud/16-1;
	UBRR0H=(baudRate>>8);
	UBRR0L=baudRate;
	UCSR0B|=(1<<RXEN0)|(1<<TXEN0);
	UCSR0C|=(1<<UCSZ01)|(1<<UCSZ00);
}

void uart_gonder(uint8_t uData){
	while(!(UCSR0A & (1<<UDRE0)));
	UDR0=uData;
}

uint8_t uart_oku(){
	while(!(UCSR0A & (1<<RXC0)));
	return UDR0;
}