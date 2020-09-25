/*
 * AVR44SPIUydu.c
 *
 * Created: 5.6.2020 14:18:45
 * Author : GDokmetas
 */ 

#include <avr/io.h>
void spi_slaveinit(void);
unsigned char spi_read(void);
int main(void)
{
    DDRD |= ((1<<PORTD2) | (1<<PORTD4));
	DDRD |=((1<<PORTD3) |(1<<PORTD5));
	PORTD &= ~((1<<PORTD3)|(1<<PORTD5));
	spi_slaveinit();
    while (1) 
    {
		unsigned char data = spi_read();
	    if (data == '1')
		PORTD ^= (1<<PORTD2);
		if (data == '2')
		PORTD ^= (1<<PORTD4);
	}
}


void spi_slaveinit(void)
{
	/* Set MISO output, all others input */
	DDRB |= (1<<DDD4);
	/* Enable SPI */
	SPCR = (1<<SPE);
}
unsigned char spi_read(void)
{
	/* Wait for reception complete */
	while(!(SPSR & (1<<SPIF)))
	;
	/* Return Data Register */
	return SPDR;
}