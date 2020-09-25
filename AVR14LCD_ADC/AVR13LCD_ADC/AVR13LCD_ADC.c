/*
 * AVR13LCD_ADC.c
 *
 * Created: 2.8.2019 15:07:03
 *  Author: Gökhan Dökmetaş
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <stdio.h>
#include <util/delay.h>
#include "lcd.h"
// Fonksiyon Prototipleri
void adc_init(void);
unsigned int read_adc(unsigned char channel);
long map(long x, long in_min, long in_max, long out_min, long out_max);
int main(void)
{
	lcd_init(LCD_DISP_ON);
	adc_init();
    while(1)
    {
    lcd_home();
	lcd_puts("HAM:");
	unsigned int adc_deger = read_adc(0);
	char lcd_ch[10]="";
	sprintf(lcd_ch, "%u", adc_deger);
	lcd_puts(lcd_ch);
	lcd_puts("   ");
	
	// ALT SATIR 
	lcd_gotoxy(0,1);
	lcd_puts("YUZDE:");
	lcd_ch[0] = '\0'; // String sıfırlandı
    long deger = map(adc_deger, 0, 1023, 0, 100);
	sprintf(lcd_ch, "%u", (int)deger);
	lcd_puts(lcd_ch);
	lcd_puts("%   ");
	
	
    }
}

void adc_init(void)
{
	ADCSRA |= ((1<<ADPS2) | (1<<ADPS1) | (1<<ADPS0));
	ADMUX |= (1<<REFS0);
	ADCSRA |= (1<<ADEN);
	ADCSRA |= (1<<ADSC);
}

unsigned int read_adc(unsigned char channel)
{
	ADMUX &= 0xF0;
	ADMUX |= channel;
	ADCSRA |= (1<<ADSC);
	while (ADCSRA & (1<<ADSC));
	return ADCW;
}

long map(long x, long in_min, long in_max, long out_min, long out_max)
{
	return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}