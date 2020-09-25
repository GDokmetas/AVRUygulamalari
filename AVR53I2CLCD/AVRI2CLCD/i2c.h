/* I2C (TwoWire) AVR library
 *
 * Copyright (C) 2015-2017 Sergey Denisov.
 * Rewritten by Sergey Denisov aka LittleBuster (DenisovS21@gmail.com)
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public Licence
 * as published by the Free Software Foundation; either version 3
 * of the Licence, or (at your option) any later version.
 */

#ifndef __I2C_H__
#define __I2C_H__

#include <avr/io.h>


/*
 * Init lib
 */
void i2c_init(void);

/*
 * Start sending data
 */
void i2c_start_condition(void);

/*
 * Stop sending data
 */
void i2c_stop_condition(void);

/**
 * Send byte to device
 * @byte: sending byte
 */
void i2c_send_byte(unsigned char byte);

/**
 * Send packet to device
 * @value: sending data
 * @address: device address
 */
void i2c_send_packet(unsigned char value, unsigned char address);

/**
 * Receive byte from device
 *
 * returns: byte
 */
unsigned char i2c_recv_byte(void);

/**
 * Receiving last byte from device
 *
 * returns: byte
 */
unsigned char i2c_recv_last_byte(void);


#endif
