#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>
#include <avr/interrupt.h>
#define BAUD 9600
#define BAUDRATE ((F_CPU)/(BAUD*16UL)-1)
void uart_basla(uint32_t baud);
void uart_gonder(uint8_t data);
void uart_string(const char *s );
uint8_t uart_oku();
int main(void)
{
	
	uart_basla(9600);
	UCSR0B |= (1<<RXCIE0);
	UCSR0B |= (1<<TXCIE0);
	sei();
	DDRD &=~ ( (1<<PD2) | (1<<PD3) | (1<<PD4) );
	// PORTD |= ((1<<PD2) | (1<<PD3) | (1<<PD4));
	PORTD = 0b11100;
	DDRD |= (1<<PD5);
	DDRD |= (1<<PD6);
	_delay_ms(100); // MCU Kendine Gelsin
	while (1)
	{
		if (!(PIND & (1<<PD2)))
		uart_string("1. Dugme Basili \n");
		if (!(PIND & (1<<PD3)))
		uart_string("2. Dugme Basili \n");
		if (!(PIND & (1<<PD4)))
		uart_string("3. Dugme Basili \n");
		
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

void uart_string(const char *s )
{
	while (*s)
	uart_gonder(*s++);

}
	
ISR (USART_RX_vect)
	{
		PORTD ^= (1<<PD5);
	}

ISR (USART_TX_vect)
	{
		PORTD ^= (1<<PD6);
	}

