/*
 * AVR47SPILibrary.c
 *
 * Created: 6.6.2020 16:15:14
 * Author : GDokmetas
 */ 

#include <avr/io.h>
#include "spi.h"

int main(void)
{
    spi_init(MASTER); 
    while (1) 
    {
		spi_transceive(0x01);
    }
}

