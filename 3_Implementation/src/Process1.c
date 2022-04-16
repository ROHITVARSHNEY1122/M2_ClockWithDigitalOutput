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
void InitialiazeADC()
{
	ADCSRA = (1<<ADEN) | (1<<ADPS2) | (1<<ADPS0);
	ADMUX = 0x00 | (1<<REFS0);					
														
}