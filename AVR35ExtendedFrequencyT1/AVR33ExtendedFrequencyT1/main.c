/*
 * AVR33ExtendedFrequencyT1.c
 *
 * Created: 13.5.2020 21:08:47
 * Author : GDokmetas
 */ 


#include <avr/io.h>


int main(void)
{
	double frekans = 100000; // de?i?tirilebilir
	DDRB |= ((1<<PB1) | (1<<PB2));
	TCCR1A = 0;
	TCCR1B = 0;
	OCR1B = 0;
	uint8_t cs_deger;
	uint16_t ocr_deger;
	if(frekans>260)
	{
		ocr_deger = 1.0/frekans / (2.0/16000000.0)-1;
		cs_deger = 1;
	}
	else if (frekans>40)
	{
		ocr_deger = 1.0/frekans / (16.0/16000000.0)-1;
		cs_deger = 2;
	}
	else if (frekans>4)
	{
		ocr_deger = 1.0/frekans / (128.0/16000000.0)-1;
		cs_deger = 3;
	}
	else if (frekans>1)
	{
		ocr_deger = 1.0/frekans / (512.0/16000000.0)-1;
		cs_deger = 4;
	}
	else
	{
		ocr_deger = 1.0/frekans / (2048.0/16000000.0)-1;
		cs_deger = 5;
	}
	OCR1A = ocr_deger;
	
	TCCR1A |= ((1<<COM1B0) | (1<<COM1A0));
	TCCR1B |= (1<<WGM12); // CTC modu
	TCCR1B |= cs_deger; 
	while (1)
	{
	}
}


