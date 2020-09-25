#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>
#include <avr/interrupt.h>
#define BAUD 9600
#define BAUDRATE ((F_CPU)/(BAUD*16UL)-1)
void uart_basla(uint32_t baud);
void uart_gonder(uint8_t data);
void uart_string(const char *s );
volatile uint8_t a;
int main(void)
{
	
	uart_basla(9600);

	sei();
	DDRD &=~ ( (1<<PD2) | (1<<PD3) | (1<<PD4) );
	// PORTD |= ((1<<PD2) | (1<<PD3) | (1<<PD4));
	PORTD = 0b11100;
	DDRD |= (1<<PD5);
	DDRD |= (1<<PD6);
	_delay_ms(100); // MCU Kendine Gelsin
	while (1)
	{
	if (a=='1')
	PORTD |= (1<<5);
	if (a=='2')
	PORTD &= ~(1<<5);
	if (a=='3')
	PORTD |= (1<<6);
	if (a=='4')
	PORTD &= ~(1<<6);
	}
}



void uart_basla(uint32_t baud){
	uint16_t baudRate=F_CPU/baud/16-1;
	UBRR0H=(baudRate>>8);
	UBRR0L=baudRate;
	UCSR0B|=(1<<RXEN0)|(1<<TXEN0);
	UCSR0C|=(1<<UCSZ01)|(1<<UCSZ00);
	UCSR0B |= (1<<RXCIE0);
}


ISR (USART_RX_vect)
{
	while(!(UCSR0A & (1<<RXC0)));
	a = UDR0;
}
