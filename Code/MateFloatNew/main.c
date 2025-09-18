/*
 * MateFloatNew.c
 *
 * Created: 4/19/2024 9:22:20 PM
 * Author : Cody G
 */ 


#include <stdint.h>
#include "config.h"
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "uart_hal.h"
#include "ADC_DAC.h"
 uint8_t ADCVal = 0;
uint8_t rawData = 0;

int main(void)
{

	
     uint8_t start[] = "Program Start\n\r";
	uint8_t data = 0;
	uint8_t depthData[16] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	uint8_t timeData[30] = {0};
		
	uart_init(38400,0);
	DDRB |= (1 << PB1 | 1 << PB2);
	TCCR1A |= (1 << COM1A1 | 1 << COM1B1 | 1 << WGM10);
	TCCR1B |= (1 << CS10 | 1 << WGM12);
	
	
	
	
	
	sei();
	uart_send_string(start);
	uart_send_string("Initalized");
   ADC_DAC_Setup();
   
   
   
    OCR1A = 255;
    OCR1B = 255;
	_delay_ms(1000);
	
   OCR1A = 0;
   OCR1B = 205;
   _delay_ms(35000);
   OCR1A = 205;
   OCR1B = 0;
   _delay_ms(25000);
    OCR1A = 0;
    OCR1B = 0;
   
    while (1) 
    {
		
		
		
		/*
		ADCSRA |= (1 << ADSC);
		while(!(ADCSRA & (1 << ADIF)));
		ADCSRA |= (1 << ADIF);
		*/
		//uart_send_byte(ADC_Read());
		//_delay_ms(100);
		
		//uart_send_byte(rawData);
		//_delay_ms(1000);
		
		if(uart_read_count() > 0){
			data = uart_read();
			
			//uart_send_byte(data);
			
			
			
			
			
			
			
			
				
		/* old code for on board motor driver, not working currently	
		OCR1A = 205;
			OCR1B = 0;
			_delay_ms(1000);
			OCR1A = 0;
			OCR1B = 205;
			_delay_ms(1000); */
			
			
			
			
			
			
			
			
		
		
	}
	
	
	
	
	
	switch (data) {
		
		
		case 0x31:
		uart_send_string("diving");

		OCR1A = 255;
		OCR1B = 255;
		_delay_ms(500);
		

		OCR1A = 0;
		OCR1B = 205;
	//	_delay_ms(25000);
		OCR1A = 0;
		OCR1B = 0;
		
		
		
		
		for(uint8_t i = 0; i < 30; i++){
			
			uint8_t currentPressure = (ADC_Read() - 20);
			depthData[i] = currentPressure;
			timeData[i] = ((i * 5) + 3);
			//uart_send_byte(currentPressure);
			_delay_ms(1000);
			
		}
		
		
		
		OCR1A = 0;
		OCR1B = 205;
		_delay_ms(35000);
		
		OCR1A = 0;
		OCR1B = 0;		
		data = 0;
		break;
		
		case 0x35:
		uart_send_string("Sending Data:");
		uart_send_array(depthData, 16);
		data = 0;
		break;
		
		
	}
		
	}
		
		
	}



void depthFind(){
	uint16_t rawData = 0;

	uart_send_byte(rawData);
}





