/*
 * AVR41EEPROMRead.c
 *
 * Created: 16.5.2020 17:43:32
 * Author : GDokmetas
 */ 

#include <avr/io.h>
#include <stdio.h>
#include <avr/interrupt.h>
#define F_CPU 16000000UL
#include <util/delay.h>
#include "uart.h"
unsigned char EEPROM_read(unsigned int uiAddress);

int main(void)
{
     sei();
     uart_init(UART_BAUD_SELECT(9600,F_CPU));
     _delay_ms(100);
     uart_puts("EEPROM OKUMA \n");
	 unsigned int address = 0;
	 unsigned char veri = 0;
	 char buf[20];
	while(1)
	{	
	veri = EEPROM_read(address);
	if (veri == 0)
	break;
	sprintf(buf,"Adres:%i    Veri:%i \n", address, veri);
	uart_puts(buf);
	address++;	 
	}
    while (1) 
    {
		
    }
}

unsigned char EEPROM_read(unsigned int uiAddress)
{
	/* Önceki okuma ve yazmanýn bitmesini bekle */
	while(EECR & (1<<EEPE))
	;
	/* Adres deðerini güncelle */
	EEAR = uiAddress;
	/* Okuma iþlemini baþlat. */
	EECR |= (1<<EERE);
	/* Veri yazmacýný deðer olarak döndür */
	return EEDR;
}