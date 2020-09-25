/*
 * AVR12KarakterLCDGiris.c
 *
 * Created: 1.8.2019 21:01:09
 *  Author: Gökhan Dökmetaş
 */ 


#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>
#include "lcd.h"

int main (void)
{
	lcd_init(LCD_DISP_ON);
	lcd_clrscr();
	lcd_home();
	char str [16];
	int pi = 30;
	sprintf(str, "Sayi = %i", pi);
	lcd_puts(str);
	while(1)
	{
	}
}