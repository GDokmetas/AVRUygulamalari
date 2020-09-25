/*
 * AVR43SPISendRecieve.c
 *
 * Created: 5.6.2020 13:44:22
 * Author : GDokmetas
 */ 


#include <avr/io.h>
unsigned char spi_send_recieve(unsigned char data);
void spi_init(void);
int main(void)
{
	spi_init();
	while (1)
	{
		unsigned char data = spi_send_recieve();
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

unsigned char spi_send_recieve(unsigned char data)
{
	/* Veriyi Yolla*/
	SPDR = data;
	/* Bitmesini Bekle */
	while(!(SPSR & (1<<SPIF)))
	;
	return SPDR;
}