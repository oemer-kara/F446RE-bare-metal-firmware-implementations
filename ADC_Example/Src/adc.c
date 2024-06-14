/*
 * adc.c
 *
 *  Created on: Jun 13, 2024
 *      Author: oemerkara
 */

#include "adc.h"

void pa1_adc_init(void)
{
    //Enable clock access to GPIOA
	RCC->AHB1ENR |= GPIOAEN;
	//Set the mode of PA1 to analog
	GPIOA->MODER |= ANALOG_MODE;

	//Configure the ADC
	//Enable clock access to ADC
	RCC->APB2ENR |= ADC1EN;
	//Configure the ADC parameters
	//Conversion sequence start
	ADC1->SQR3 |= ADC_CH1;
	//Conversion sequence length
	//Enable ADC module


}