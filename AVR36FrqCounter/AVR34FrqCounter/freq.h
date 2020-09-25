/*
 * freq.h
 *
 * Created: 14.5.2020 14:30:39
 *  Author: GDokmetas
 */ 



/*
  FreqCounter.h - Library for a Frequency Counter c.
  Created by Martin Nawrath, KHM Lab3, Dec. 2008
  Released into the public domain.
*/



#ifndef freq_h
#define freq_h


#include <avr/interrupt.h>


	extern unsigned long f_freq;
	extern volatile unsigned char f_ready;
	extern volatile unsigned char f_mlt;
	extern volatile unsigned int f_tics;
	extern volatile unsigned int f_period;
	extern volatile unsigned int f_comp;
	void freq_start(int ms);

#endif





