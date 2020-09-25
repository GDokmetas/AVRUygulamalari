/*
 * spi.c
 *
 * Created: 6.6.2020 16:16:34
 *  Author: GDokmetas
 */ 
#include <avr/io.h>
#include "spi.h"


void spi_init(uint8_t mode)
{
	if (SPI_DATA_ORDER == MSB_FIRST)
	{
		SPCR &= ~(1<<DORD);
	}
	else
	{
		SPCR |= (1<<DORD);
	}
	if(mode == SLAVE)
	{
			// MISO OUTPUT, OTHERS INPUT
			DDRB |= (1<<DDD4);
			/* Enable SPI */
			SPCR = (1<<SPE);
	}
	else
	{
			// MOSI , SCK OUTPUT
			DDRB |= (1<<DDB3)|(1<<DDB5);
			DDRB |= (1<<DDB2); //SS OUTPUT
			/*SPI Enable, Master Mod */
			SPCR |= ((1<<SPE)|(1<<MSTR));
			SPCR |= (SPI_CLOCK_RATE); 
			SPSR |= (SPI_SPEED);
	}
}

uint8_t spi_transceive(uint8_t data)
{
	/* Send data */
	SPDR = data;
	/* wait for end of transmission */
	while(!(SPSR & (1<<SPIF)))
	;
	return SPDR;
}

unsigned char spi_read(void)
{
	/* Wait for reception complete */
	while(!(SPSR & (1<<SPIF)))
	;
	/* Return Data Register */
	return SPDR;
}

void spi_interrupt(uint8_t status)
{
	if (status == ENABLE)
	{
		SPCR |= (1<<SPIE);
	}
	else
	{
		SPCR &= ~(1<<SPIE);
	}
}

void spi_mode(uint8_t mode)
{
	switch(mode)
	{
	case 0:
	SPCR &= ~((1<<CPOL) | (1<<CPHA));
	break;
	case 1:
	SPCR &= ~(1<<CPOL);
	SPCR |= (1<<CPHA);
	break;
	case 2:
	SPCR |= (1<<CPOL);
	SPCR &= ~(1<<CPHA);
	break;
	case 3:
	SPCR |= ((1<<CPOL) | (1<<CPHA));
	}
}