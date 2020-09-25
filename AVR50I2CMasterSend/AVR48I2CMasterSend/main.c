/*
 * AVR48I2CMasterSend.c
 *
 * Created: 25.6.2020 07:02:05
 * Author : GDokmetas
 */ 

#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>
void i2c_init();
void i2c_start();
void i2c_write(unsigned char data);
void i2c_stop();
int main(void)
{
	i2c_init();
	i2c_start();
	i2c_write(0x3F << 1);
	i2c_write(0x00);
	i2c_stop();
	while(1)
	{

	}
}


void i2c_init()
{
	TWSR = 0x00;
	TWBR = 0x72;
	TWCR = 0x04;
}

void i2c_start()
{
	TWCR = ((1<<TWINT) | (1<<TWSTA) | (1 << TWEN));
	while ((TWCR & (1<<TWINT)) == 0);
}

void i2c_stop()
{
	TWCR = ((1<<TWINT) | (1<<TWEN) | (1<<TWSTO));
}

void i2c_write (unsigned char data)
{
	TWDR = data;
	TWCR = ((1<<TWINT) | (1<<TWEN));
	while ((TWCR & (1<<TWINT)) == 0);
}