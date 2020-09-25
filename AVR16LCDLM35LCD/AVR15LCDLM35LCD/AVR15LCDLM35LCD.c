
#define F_CPU 16000000UL
#include <avr/io.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
	unsigned int adc_deger = read_adc(0);
    long deger = map(adc_deger, 0, 1023, 0, 100);
	if (deger>80)
		{
			lcd_puts("AYDINLIK");
		}
    else if (deger > 50)
		{
			lcd_puts("GOLGE");
		}
	else
		{
			lcd_puts("KARANLIK");
		}
	lcd_puts("     "); // boşluk yazdırma
	
	//LM35 ve sıcaklık yazdırma
	unsigned int lm35_ham = read_adc(1);
	float mv = ( lm35_ham/1024.0)*5000;
	float cel = mv/10;
	char lcd_str[5];
	sprintf(lcd_str,"%i",(int)cel);
	lcd_gotoxy(0,1);
	lcd_puts("SICAKLIK:");

	lcd_puts(lcd_str);
	lcd_puts("    ");
	_delay_ms(200);
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