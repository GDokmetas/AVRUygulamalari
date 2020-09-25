/*
 * AVR46ShiftRegister.c
 *
 * Created: 5.6.2020 17:35:04
 * Author : GDokmetas
 */ 


#include <avr/io.h>
void spi_transmit(unsigned char data);
void spi_init(void);
#define  F_CPU 16000000UL
#include <util/delay.h>
int main(void)
{
	spi_init();
	while (1)
	{
		/*
		PORTB &= ~(1<<PORTB2);
		spi_transmit(0xFF);
		PORTB |= (1<<PORTB2);
		_delay_ms(500);
		PORTB &= ~(1<<PORTB2);
		spi_transmit(0x00);
		PORTB |= (1<<PORTB2);
		_delay_ms(500);
		*/
		for (int i = 0; i<255; i++)
		{
			PORTB &= ~(1<<PORTB2);
			spi_transmit(i);
			PORTB |= (1<<PORTB2);
			_delay_ms(80);
		}
	}
}

void spi_init(void)
{
	/* MOSI ve SCK Çýkýþ, Diðerleri Giriþ*/
	DDRB |= (1<<DDB3)|(1<<DDB5);
	DDRB |= (1<<DDB2); // SS ÇIKIÞ ÖNEMLÝ
	/*SPI Enable, Master Mod, Fcpu/16*/
	SPCR |= ((1<<SPE)|(1<<MSTR)|(1<<SPR0));
}

void spi_transmit(unsigned char data)
{
	/* Veriyi Yolla*/
	SPDR = data;
	/* Bitmesini Bekle */
	while(!(SPSR & (1<<SPIF)))
	;
	
}