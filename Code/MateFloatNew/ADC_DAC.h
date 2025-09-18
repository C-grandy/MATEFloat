/*
 * ADC_DAC.h
 *
 * Created: 5/8/2024 4:02:50 PM
 *  Author: Cody G
 */ 


#ifndef ADC_DAC_H_
#define ADC_DAC_H_



#include <stdint.h>
#include "config.h"
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

void ADC_DAC_Setup();
//void DAC_Write(uint8_t value);
uint16_t ADC_Read(void);







#endif /* ADC_DAC_H_ */