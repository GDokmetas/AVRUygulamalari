/*
 * AVR16InternalTemperatureSensor.c
 *
 * Created: 2.8.2019 18:28:32
 *  Author: Gökhan Dökmetaş
 */ 


#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>
#include <stdlib.h>
#include "lcd.h"
unsigned int Ctemp;
unsigned int Ftemp;
int main(void)
{
	
	lcd_init(LCD_DISP_ON);
    /* Setup ADC to use int 1.1V reference 
    and select temp sensor channel */
    ADMUX = (1<<REFS1) | (1<<REFS0) | (0<<ADLAR) | (1<<MUX3) | (0<<MUX2) | (0<<MUX1) | (0<<MUX0);

    /* Set conversion time to 
    112usec = [(1/(8Mhz / 64)) * (14 ADC clocks  per conversion)]
     and enable the ADC*/
    ADCSRA = (1<<ADPS2) | (1<<ADPS1) | (1<<ADEN);

    /* Perform Dummy Conversion to complete ADC init */
    ADCSRA |= (1<<ADSC);

    /* wait for conversion to complete */
    while ((ADCSRA & (1<<ADSC)) != 0);
	
    while(1)
    {
     /* start a new conversion on channel 8 */
     ADCSRA |= (1<<ADSC);

     /* wait for conversion to complete */
     while ((ADCSRA & (1<<ADSC)) != 0);

     /* Calculate the temperature in C */
     Ctemp = (ADC - 247)/1.22;
     Ftemp = (Ctemp * 1.8) + 32;
	 
	 char lcd_ch[10]="";
	 itoa((int)Ctemp, lcd_ch, 10);
	 lcd_home();
	 lcd_puts(lcd_ch);
	 lcd_puts("C     ");
    }
}


