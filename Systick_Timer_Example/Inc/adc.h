/*
 * adc.h
 *
 *  Created on: Jun 13, 2024
 *      Author: oemerkara
 */

#ifndef ADC_H_
#define ADC_H_

#include "stm32f446xx.h"

/** @defgroup ADC_Constants ADC Constants
 * @{
 */

#define ADC1EN      (1U << 8)  /**< Enable ADC1 */
#define GPIOAEN     (1U << 0)  /**< Enable GPIOA */
#define ADC_CH1     (1U << 0)  /**< ADC Channel 1 */
#define ADC_SEQ_LEN 0x00       /**< ADC Sequence Length */
#define CR2_ADON    (1U << 0)  /**< Control Register 2, ADC ON */
#define CR2_SWSTART (1U << 30) /**< Control Register 2, Start Conversion */
#define SR_EOC      (1U << 1)  /**< Status Register, End of Conversion */

/** @} */     // end of ADC_Constants

/**
 * @brief Reads the ADC conversion result.
 *
 * This function reads the value from the ADC data register and returns the
 * digital representation of the analog input.
 *
 * @return uint32_t The ADC conversion result.
 */
uint32_t adc_read(void);

/**
 * @brief Starts the ADC conversion process.
 *
 * This function sets the SWSTART bit in the ADC control register to start
 * the analog-to-digital conversion process.
 */
void start_conversion(void);

/**
 * @brief Initializes ADC on PA1.
 *
 * This function configures the necessary GPIO and ADC settings to enable
 * analog-to-digital conversion on the PA1 pin.
 */
void pa1_adc_init(void);

#endif /* ADC_H_ */
