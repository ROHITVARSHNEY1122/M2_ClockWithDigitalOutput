#define F_CPU 16000000UL
#define PORT_ON(port, pin) port |= (1 << pin)
#define PORT_OFF(port, pin) port &= ~(1 << pin)
#define true 1
#define false 0
#include <avr/io.h>
#include <avr/interrupt.h>
#include "util/delay.h"
#include <stdbool.h>
#include "Process1.h"
#include "Process2.h"
#include "Process3.h"
#include "Process4.h"

void InitialiazeADC();

uint16_t Read_ADC(uint8_t CHANNEL);

uint8_t HOURS = 0;

uint8_t MINUTES = 0;

uint8_t SECONDS = 0;
uint8_t Main_Display[14][7] = {

	{0, 0, 1, 1, 0, 0, 1},
	{0, 1, 1, 1, 0, 1, 1},
	{0, 0, 1, 1, 0, 0, 1},
	{0, 1, 1, 1, 0, 1, 1},
	{1, 1, 1, 1, 1, 1, 0},
	{0, 1, 1, 0, 0, 0, 0},
	{1, 1, 0, 1, 1, 0, 1},
	{1, 1, 1, 1, 0, 0, 1},
	{0, 1, 1, 0, 0, 1, 1},
	{1, 0, 1, 1, 0, 1, 1},
	{1, 0, 1, 1, 1, 1, 1},
	{1, 1, 1, 0, 0, 0, 0},
	{1, 1, 1, 1, 1, 1, 1},
	{1, 1, 1, 0, 0, 1, 1}

};


void SecondsToCalculate(bool display_time)

{

	switch (display_time)
	{

	case 0:

		if (SECONDS / 10 == 0 && SECONDS < 10)
		{
			Displayprinting(0, 1);
		}
		if (SECONDS / 10 == 0 && SECONDS < 10)
		{
			Displayprinting(SECONDS, 0);
		}

		else if (SECONDS % 10 != 0)
		{
			Displayprinting(SECONDS / 10, 1);
		}

		else if (SECONDS % 10 != 0)
		{
			Displayprinting(SECONDS % 10, 0);
		}
		else if (SECONDS % 10 == 0)
		{
			Displayprinting(SECONDS / 10, 1);
		}
		else if (SECONDS % 10 == 0)
		{
			Displayprinting(0, 0);
		}
		break;

	case 1:
		if (SECONDS / 10 == 0 && SECONDS < 10)
		{
			Displayprinting(0, 1);
			_delay_ms(50);
		}
		if (SECONDS / 10 == 0 && SECONDS < 10)
		{
			Displayprinting(SECONDS, 0);
			_delay_ms(50);
		}

		else if (SECONDS % 10 != 0)
		{
			Displayprinting(SECONDS / 10, 1);
			_delay_ms(50);
			}
			else if (SECONDS % 10 != 0)
		{
			Displayprinting(SECONDS % 10, 0);
			_delay_ms(50);
		}

		else if (SECONDS % 10 == 0)
		{
			Displayprinting(SECONDS / 10, 1);
			_delay_ms(50);
		}
			else if (SECONDS % 10 == 0)
		{
			Displayprinting(0, 0);
			_delay_ms(50);
		}
		break;
	}
}
void MinutesToCalculate(bool display_time)
{
	switch (display_time)
	{
	case 0:
		if (MINUTES / 10 == 0 && MINUTES < 10)
		{
			Displayprinting(0, 1);
		}
			else if (SECONDS % 10 == 0)
		{
			Displayprinting(MINUTES, 0);
		}

		else if (MINUTES % 10 == 0)
		{
			Displayprinting(MINUTES / 10, 1);
		}
		else if (MINUTES % 10 == 0)
		{
			Displayprinting(0, 0);
		}

		else if (MINUTES % 10 != 0)
		{
			Displayprinting(MINUTES / 10, 1);
		}
		else if (MINUTES % 10 != 0)
		{
			Displayprinting(MINUTES % 10, 0);
		}
		break;

	case 1:
		if (MINUTES / 10 == 0 && MINUTES < 10)
		{
			Displayprinting(0, 1);
			_delay_ms(50);
		}
			if (MINUTES / 10 == 0 && MINUTES < 10)
		{
			Displayprinting(MINUTES, 0);
			_delay_ms(50);
		}

		else if (MINUTES % 10 == 0)
		{
			Displayprinting(MINUTES / 10, 1);
			_delay_ms(50);
		}
				else if (MINUTES % 10 == 0)
		{
			Displayprinting(0, 0);
			_delay_ms(50);
		}

		else if (MINUTES % 10 != 0)
		{
			Displayprinting(MINUTES / 10, 1);
			_delay_ms(50);
		}
		else if (MINUTES % 10 != 0)
		{

			Displayprinting(MINUTES % 10, 0);
			_delay_ms(50);
		}
		break;
	}
}
void HoursToCalculate(bool display_time)
{
	switch (display_time)
	{
	case 0:
		if (HOURS / 10 == 0)
		{
			Displayprinting(0, 3);
		}
			if (HOURS / 10 == 0)
		{
			Displayprinting(HOURS, 2);
		}

		else
		{
			Displayprinting(1, 3);
			Displayprinting(HOURS % 10, 2);
		}
		break;

	case 1:
		if (HOURS / 10 == 0)
		{
			Displayprinting(0, 3);
			_delay_ms(100);
		}
		if (HOURS / 10 == 0)
		{
			Displayprinting(HOURS, 2);
			_delay_ms(100);
		}

		else
		{
			Displayprinting(1, 3);
			_delay_ms(100);
			Displayprinting(HOURS % 10, 2);
			_delay_ms(100);
		}
		break;
	}
}

void Displayprinting(uint8_t DIGIT, uint8_t NUMBERDISPLAY)
{
	uint8_t pin = 2;
	PORTD &= 0b00000000;
	PORTB &= (0 << PB0);
	PORTB &= (0 << PB1);

	if (NUMBERDISPLAY == 0)
	{
		PORTB &= (0 << PB2);
		PORTB |= (1 << PB3);
		PORTB |= (1 << PB4);
		PORTB |= (1 << PB5);
	}

	else if (NUMBERDISPLAY == 1)
	{
		PORTB &= (0 << PB3);
		PORTB |= (1 << PB2);
		PORTB |= (1 << PB4);
		PORTB |= (1 << PB5);
	}

	else if (NUMBERDISPLAY == 2)
	{
		PORTB &= (0 << PB4);
		PORTB |= (1 << PB2);
		PORTB |= (1 << PB3);
		PORTB |= (1 << PB5);
	}

	else if (NUMBERDISPLAY == 3)
	{
		PORTB &= (0 << PB5);
		PORTB |= (1 << PB2);
		PORTB |= (1 << PB3);
		PORTB |= (1 << PB4);
	}

	for (int triple = 0; triple < 7; ++triple)
	{
		uint8_t pin, DIGIT;
		if (pin < 8)
			PORTD |= (Main_Display[DIGIT][triple] << pin);
		else
			PORTB |= (Main_Display[DIGIT][triple] << 0);
		++pin;
	}
}

int main(void)
{
	uint8_t pin, DIGIT;
	uint16_t adc_value;
	DDRD = 0b11111100;
	DDRB = 0b00111111;

	PORTB |= (0 << PB2);
	PORTB |= (1 << PB3);
	PORTB |= (1 << PB4);
	PORTB |= (1 << PB5);

	InitialiazeADC();

	OCR1A = 0x3D08;
	TCCR1B |= (1 << WGM12);
	TIMSK1 |= (1 << OCIE1A);
	TCCR1B |= (1 << CS12) | (1 << CS10);
	sei();

	PORT_OFF(PORTB, 1);

	for (;;)
	{

		adc_value = Read_ADC(1);
		if (adc_value > 750)
		{
			cli();
			MINUTES += 1;

			if (MINUTES > 59)
			{
				HOURS += 1;
				MINUTES = 0;
			}

			if (HOURS > 11)
			{
				HOURS = 0;
			}

			MinutesToCalculate(1);
			MinutesToCalculate(1);
			HoursToCalculate(1);
			HoursToCalculate(1);
			sei();
		}

		adc_value = Read_ADC(2);
		if (adc_value > 750)
		{
			cli();
			HOURS += 1;

			if (HOURS > 11)
			{
				HOURS = 0;
			}
			MinutesToCalculate(1);
			MinutesToCalculate(1);
			HoursToCalculate(1);
			HoursToCalculate(1);
			sei();
		}
		MinutesToCalculate(0);
		MinutesToCalculate(0);
		HoursToCalculate(0);
		HoursToCalculate(0);
	}
}
