/*
 * ADC_DAC.c
 *
 * Created: 5/8/2024 3:56:15 PM
 *  Author: Cody G
 */ 

#include "ADC_DAC.h"
 //uint16_t ADCVal = 0;

void ADC_DAC_Setup() {

ADMUX |= (1 << REFS0) |(1 << ADLAR) | (1 << MUX0);
ADCSRA |= (1 << ADEN)  | (1 << ADPS0) | (1 << ADPS1) | (1 << ADPS2);
DIDR0 |= (1 << ADC1D);

ADCSRA |= (1 << ADSC);
}







uint16_t ADC_Read(void)  {
	
	ADCSRA|=(1<<ADSC); // start conversion
	while(!(ADCSRA & (1<<ADIF))); // waiting for ADIF, conversion complete
	ADCSRA|=(1<<ADIF); // clearing of ADIF, it is done by writing 1 to it
	
	return (ADCH);
	
	
	//return ADCVal;
}
/*
ISR(ADC_vect){
	ADCVal = ADC;
	
	ADCSRA |= (1 << ADSC);
}
*/