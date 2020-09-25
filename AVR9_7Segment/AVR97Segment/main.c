/*
 * AVR97Segment.c
 *
 * Created: 31.7.2019 13:50:03
 * Author : Gökhan Dökmetaş
 */ 

#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>


int main() {
	char seg_code[]={0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0xff,0x6F};
	
	DDRD = 0xff; 

	while (1)
	{
		for (int cnt = 0x00; cnt < 9; cnt++) // loop to display 0-9999
		{
			
				PORTD = seg_code[cnt];
				_delay_ms(1000);

		}
	}
}

