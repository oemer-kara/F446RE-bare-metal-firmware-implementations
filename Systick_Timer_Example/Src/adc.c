/*
 * adc.c
 *
 *  Created on: Jun 13, 2024
 *      Author: oemerkara
 */

#include "adc.h"

/**
 * @brief Initializes ADC on PA1.
 *
 * This function configures the necessary GPIO and ADC settings to enable
 * analog-to-digital conversion on the PA1 pin.
 *
 * Steps:
 * - Enables clock access to GPIOA.
 * - Sets the mode of PA1 to analog.
 * - Enables clock access to ADC1.
 * - Configures the ADC parameters (conversion sequence and length).
 * - Enables the ADC module.
 */
void pa1_adc_init(void)
{
    // Enable clock access to GPIOA
    RCC->AHB1ENR |= GPIOAEN;
    // Set the mode of PA1 to analog
    GPIOA->MODER |= (1U<<2);
    GPIOA->MODER |= (1U<<3);

    // Configure the ADC
    // Enable clock access to ADC1
    RCC->APB2ENR |= ADC1EN;
    // Configure the ADC parameters
    // Conversion sequence start
    ADC1->SQR3 |= ADC_CH1;
    // Conversion sequence length
    ADC1->SQR1 = ADC_SEQ_LEN;
    // Enable ADC module
    ADC1->CR2 |= CR2_ADON;
}

/**
 * @brief Starts the ADC conversion process.
 *
 * This function sets the SWSTART bit in the ADC control register to start
 * the analog-to-digital conversion process.
 */
void start_conversion(void)
{
    ADC1->CR2 |= CR2_SWSTART;
}

/**
 * @brief Reads the ADC conversion result.
 *
 * This function reads the value from the ADC data register and returns the
 * digital representation of the analog input.
 *
 * @return uint32_t The ADC conversion result.
 */
uint32_t adc_read(void)
{
    // Wait for conversion to be complete
    while(!(ADC1->SR & SR_EOC)){}
    // Read converted result
    return ADC1->DR;
}
