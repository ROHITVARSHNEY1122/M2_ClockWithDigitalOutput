#define F_CPU 16000000UL
#define PORT_ON(port,pin) port |= (1<<pin)
#define PORT_OFF(port,pin) port &= ~(1<<pin)
#define true 1
#define false 0
#include<avr/io.h>
#include<avr/interrupt.h>
#include"util/delay.h"
#include<stdbool.h>
#include"Process1.h"
#include"Process2.h"
#include"Process3.h"
#include"Process4.h"
uint16_t Read_ADC(uint8_t channel)
{
	uint16_t adc_value;

	ADMUX &= 0xF0;
	ADMUX = channel | (1 << REFS0);
	ADCSRA |= (1 << ADSC);
	while (ADCSRA & (1 << ADSC))
		;

	adc_value = ADCW;
	return adc_value;
}