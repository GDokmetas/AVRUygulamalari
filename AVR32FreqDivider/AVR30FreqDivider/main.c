/*
 * AVR30FreqDivider.c
 *
 * Created: 13.5.2020 12:42:56
 * Author : GDokmetas
 */ 

#include <avr/io.h>
#define F_CPU 16000000UL
#include <avr/interrupt.h>

int main(void)
{
	DDRC |= (1<<PC5);
	DDRD |= (1<<PORTD6);
	DDRD &= ~(1<<PORTD4);
	TCCR0A |= (1<<WGM01); // CTC MOD
	TCCR0A |= (1<<COM0A0);
	TCCR0B |= (1<<CS01);
	TCCR0B |= (1<<CS02);
	OCR0A = 1;
	
	 unsigned long frekans = 10000UL; // deðiþtirilebilir
    DDRB |= ((1<<PB1) | (1<<PB2));
    TCCR1A = 0;
    TCCR1B = 0;
    OCR1B = 0;
    
    int ocr_deger = 1.0/frekans / (2.0/16000000.0)-1;
    OCR1A = ocr_deger;
    
    TCCR1A |= ((1<<COM1B0) | (1<<COM1A0));
    TCCR1B |= (1<<WGM12); // CTC modu
    TCCR1B |= (1<<CS10); // 8x prescaler
	while (1)
	{
	}
}


