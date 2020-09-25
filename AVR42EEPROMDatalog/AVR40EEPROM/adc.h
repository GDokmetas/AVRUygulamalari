#ifndef ADC_H
#define ADC_H
/*
    AVR Atmega328P ADC Library
    Written By Gökhan Dökmetaş 2020 
    www.lojikprob.com
*/
// INCLUDES 
#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdint.h>
// USER CONFIGURATIONS 
//**********************BEGINNING OF USER CONFIGURATIONS ****************************//
#define ADC_REFERENCE ADC_REF_VCC

/*  Define Your ADC Reference 
    ADC_REF_EXTERNAL : AVCC Pin
    ADC_REF_VCC      : Power Supply
    ADC_REF_INTERNAL : Internal 1.1V Reference 
*/ 
#define ADC_PRESCALER ADC_DIV128 
/* 
   Define Prescaler Value 
   ADC_DIV2 /2 
   ADC_DIV3 /3
   ADC_DIV4 /4
   ADC_DIV8 /8
   ADC_DIV16 /16
   ADC_DIV32 /32
   ADC_DIV64 /64
   ADC_DIV128 /128
*/
#define TRIGGER_SOURCE FREE_RUN 
/* 
    Define Trigger Source 
    FREE_RUN 
    ANALOG_C  // Analog Comparator 
    EXINT_0  // External Interrupt Request 0
    TC0_COMP_A // Timer/Counter0 Compare Match A
    TC0_FLOW // Timer/Counter0 Overflow
    TC1_COMP_B // Timer/Counter1 Compare Match B 
    TC1_FLOW  // Timer/Counter1 Overflow 
    TC1_CAPTURE // Timer/Counter1 Capture Event
*/
// USE adc_autotrig(uint8_t mode) function to enable trigger sources

// ADC INTERRUPTS 
// adc_interrupt(ENABLE) to Enable ADC Interrupt 
// adc_interrupt(DISABLE) to Disable ADC Interrupt 

/*
    DIGITAL PIN DISABLE 
    USE adc_disable_digital(int pins); function to disable digital pins for 
    reduce power consumption. 
    DISABLE_NONE 0 // ENABLE Digital Pins 
    DISABLE_0   // Disable Pin 0
    DISABLE_1   // Disable Pin 1
    DISABLE_2   // Disable Pin 2
    DISABLE_3   // Disable Pin 3
    DISABLE_4   // Disable Pin 4 
    DISABLE_5   // Disable Pin 5
    DISABLE_ALL // Disable All Pins 

//****************** END OF USER CONFIGURATIONS ***********************************/
// Definitions and Macros
// 
#define adc_set_channel(channel) (ADMUX |= channel)

// ADC reference values
#define ADC_REF_EXTERNAL 0
#define ADC_REF_VCC      1
#define ADC_REF_INTERNAL 3  // 0b11 

// ADC Prescaler Values 
#define ADC_DIV2     0
//#define ADC_DIV2     1
#define ADC_DIV4     2
#define ADC_DIV8     3
#define ADC_DIV16    4
#define ADC_DIV32    5
#define ADC_DIV64    6
#define ADC_DIV128   7

// ADC Auto Trigger Source Values 
#define FREE_RUN    0
#define ANALOG_C    1
#define EXINT_0     2
#define TC0_COMP_A  3
#define TC0_FLOW    4
#define TC1_COMP_B  5
#define TC1_FLOW    6
#define TC1_CAPTURE 7
// STATUS 
#define DISABLE 0 
#define ENABLE  1
// Disable Digital Pins 
#define DISABLE_NONE 0 
#define DISABLE_0    1
#define DISABLE_1    2
#define DISABLE_2    4
#define DISABLE_3    8
#define DISABLE_4    16
#define DISABLE_5    32
#define DISABLE_ALL  63

// Functions 

// init adc 
extern void adc_init(void);
// deinit adc 
extern void adc_deinit();
// Start converstaion and return data (single & first of free-run)
extern uint16_t adc_read(uint8_t channel);
// Return only ADC data, use at free-run and other trigger sources
extern uint16_t adc_read_data();
// Enable and select autotrigger sources 
extern void adc_autotrig(uint8_t mode);
//Enable or disable ADC interrupt 
extern void adc_interrupt(uint8_t status);
// Disable digital inputs for reduce power consumption
extern void adc_disable_digital(uint8_t pins);
// ADC Left Adjust 
extern void adc_left_adjust(); 
// Read ADC with reduced noise 
extern uint16_t adc_read_smooth(uint8_t channel);
// ADC Read + Map Function 
extern long adc_read_map(uint8_t channel, long out_min, long out_max);
#endif // 328P_ADC_H