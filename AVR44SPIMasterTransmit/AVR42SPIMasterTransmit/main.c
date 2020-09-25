/*
 * AVR42SPIMasterTransmit.c
 *
 * Created: 5.6.2020 12:34:57
 * Author : GDokmetas
 */ 

#include <avr/io.h>
void spi_transmit(unsigned char data);
void spi_init(void);
int main(void)
{
	spi_init();
    while (1) 
    {
    spi_transmit(0xFF);
	spi_transmit(0x00);
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