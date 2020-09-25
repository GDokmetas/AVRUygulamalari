/*
 * AnalogComparator.c
 *
 * Created: 15.5.2020 15:32:19
 *  Author: GDokmetas
 */ 
#include "AnalogComparator.h"
#include <avr/io.h>

void ac_status(int status)
{
	if (status == ENABLE)
	{
		ACSR &= ~(1<<ACD);
	}
	else
	if (status == DISABLE)
	{
		ACSR |= (1<<ACD);
	}
}

void ac_bandgap_select(int bandgap)
{
	if (bandgap == BANDGAP_FIX)
	{
		ACSR &= ~(1<<ACBG);
	}
	else
	if (bandgap == BANDGAP_AIN)
	{
		ACSR |= (1<<ACBG);
	}
}

int ac_read()
{
	return  ACSR & (1<<ACO);
}

int ac_int_flag()
{
	return  ACSR & (1<<ACI);
}

void ac_int(int status, int mode)
{
	if (status == DISABLE)
	{
		ACSR &= ~(1<<ACIE);
	}
	else
	if (status == ENABLE)
	{
		ACSR |= (1<<ACIE);
	}
	switch (mode)
	{
		case INT_TOGGLE:
		ACSR &=~ ( (1<<ACIS1) | (1<<ACIS0));
		break;
		case INT_FALLING:
		ACSR &=~ (1<<ACIS0);
		ACSR |= (1<<ACIS1);
		break;
		case INT_RISING:
		ACSR |= ( (1<<ACIS0) | (1<<ACIS1) );
		break;
		default:
		break;
	}
}

void ac_capture(int status)
{
	if (status == DISABLE)
	{
		ACSR &= ~(1<<ACIC);
	}
	else
	if (status == ENABLE)
	{
		ACSR |= (1<<ACIC);
	}
}