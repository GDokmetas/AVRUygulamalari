/*
 * AVR45SPIAna.c
 *
 * Created: 5.6.2020 14:25:45
 * Author : GDokmetas
 */ 

/*
 * AVR43SPISendRecieve.c
 *
 * Created: 5.6.2020 13:44:22
 * Author : GDokmetas
 */ 


#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>
unsigned char spi_send_recieve(unsigned char data);
void spi_init(void);
int main(void)
{
	spi_init();
	while (1)
	{
		spi_send_recieve('1');
		_delay_ms(500);
		spi_send_recieve('2');
		_delay_ms(500);
		spi_send_recieve('1');
		_delay_ms(500);
		spi_send_recieve('2');
		_delay_ms(500);
	}
}

void spi_init(void)
{
	
	DDRB |= (1<<DDB3)|(1<<DDB5);
	DDRB |= (1<<DDB2); 
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