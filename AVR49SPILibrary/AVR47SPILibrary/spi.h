/*
 * spi.h
 *
 * Created: 6.6.2020 16:15:57
 *  Author: GDokmetas
 */ 


#ifndef SPI_H_
#define SPI_H_
// USER CONFIGURATIONS 
#define SPI_DATA_ORDER MSB_FIRST
#define SPI_DEFAULT_MODE SPI_MODE_0
#define SPI_CLOCK_RATE SPI_CLOCKDIV_4
#define SPI_SPEED SPI_DOUBLESPEED

// Macros and Functions 
#define spi_deinit() SPCR &= ~(1<<SPE) /* deinit SPI, if you need */
void spi_init(uint8_t mode);
uint8_t spi_transceive(uint8_t data);
void spi_interrupt(uint8_t status);
void spi_mode(uint8_t mode);
unsigned char spi_read(void);





// Definitions 
#define SLAVE 0
#define MASTER 1

#define ENABLE 1
#define DISABLE 0

#define MSB_FIRST 1
#define LSB_FIRST 0

#define SPI_MODE_0 0
#define SPI_MODE_1 1
#define SPI_MODE_2 2
#define SPI_MODE_3 3

#define SPI_CLOCKDIV_4 0b00
#define SPI_CLOCKDIV_16 0b01
#define SPI_CLOCKDIV_64 0b10
#define SPI_CLOCKDIV_128 0b11

#define SPI_DOUBLESPEED 1
#define SPI_REGULARSPEED 0




#endif /* SPİ_H_ */