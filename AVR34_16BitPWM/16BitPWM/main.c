/*
 * 16bitPWM.c
 *
 * Created: 26.12.2018 08:54:53
 * Author : Gökhan Dökmetaþ
 */ 

#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>

int main()
{
	
	DDRB|=(1<<PB1); // PB1 yani OC1A PWM çýkýþý
	TCCR1A|=((1<<COM1A1) ); //Yukarý sayýmda eþleþme olunca OC1A/OC1B'yi sýfýrla
	TCCR1B|=(1<<WGM13); // Faz ve frekans düzeltmeli PWM etkin.
	TCCR1B|=(1<<CS10); // Ön derecelendirici katsayýsý 1 (F_CPU)
	ICR1=65535; // TOP deðerini ayarla. (Çözünürlük)
	OCR1A=0; // Karþýlaþtýrma deðerini sýfýrla
	
	while (1)
	{
    OCR1A++;  // Karþýlaþtýrma deðerini her döngüde bir artýr
	_delay_us(50);
	}
}

