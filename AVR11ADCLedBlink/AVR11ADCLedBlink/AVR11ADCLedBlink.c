/*
 * AVR11ADCLedBlink.c
 *
 * Created: 1.8.2019 18:46:50
 *  Author: Gökhan Dökmetaş */ 
#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>
void adc_init();
unsigned int read_adc(unsigned char channel);
void __delay_ms(int n);
int main(void)
{
	adc_init();
	DDRD |= (1<<PD2);
	while (1)
	{
		unsigned int bekleme = 0;
		int adc = read_adc(0);
		bekleme = adc;
		PORTD |= (1<<PD2);
		__delay_ms(bekleme);
		PORTD &=~(1<<PD2);
		__delay_ms(bekleme);
		
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

void __delay_ms(int n) {
	while(n--) {
		_delay_ms(1);
	}
}