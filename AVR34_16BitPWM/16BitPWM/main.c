/*
 * 16bitPWM.c
 *
 * Created: 26.12.2018 08:54:53
 * Author : G�khan D�kmeta�
 */ 

#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>

int main()
{
	
	DDRB|=(1<<PB1); // PB1 yani OC1A PWM ��k���
	TCCR1A|=((1<<COM1A1) ); //Yukar� say�mda e�le�me olunca OC1A/OC1B'yi s�f�rla
	TCCR1B|=(1<<WGM13); // Faz ve frekans d�zeltmeli PWM etkin.
	TCCR1B|=(1<<CS10); // �n derecelendirici katsay�s� 1 (F_CPU)
	ICR1=65535; // TOP de�erini ayarla. (��z�n�rl�k)
	OCR1A=0; // Kar��la�t�rma de�erini s�f�rla
	
	while (1)
	{
    OCR1A++;  // Kar��la�t�rma de�erini her d�ng�de bir art�r
	_delay_us(50);
	}
}

