/*
 * AVRI2CLCD.c
 *
 * Created: 29.6.2020 09:35:53
 * Author : GDokmetas
 */ 

#include <avr/io.h>
#define F_CPU 16000000UL
#include "lcd1602.h"

int main(void)
{
    lcd1602_init();
	lcd1602_send_string("Merhaba Dunya");
    while (1) 
    {

    }
}

