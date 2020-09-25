/*
 * AnalogComparator.h
 *
 * Created: 15.5.2020 15:31:38
 *  Author: GDokmetas
 */ 


#ifndef ANALOGCOMPARATOR_H_
#define ANALOGCOMPARATOR_H_

// Written By Gökhan Dökmetaþ
// www.lojikprob.com

#define INT_TOGGLE 0
#define INT_FALLING 1
#define INT_RISING 2

#define BANDGAP_FIX 0
#define BANDGAP_AIN 1

#define DISABLE 0  // STATUS
#define ENABLE 1

void ac_status(int status);

void ac_bandgap_select(int bandgap);

int ac_read();  // return ACO

int ac_int_flag(); // Return ACI

void ac_int(int status, int mode); // Interrupt Enable

void ac_capture(int status); // Capture Enable




#endif /* ANALOGCOMPARATOR_H_ */