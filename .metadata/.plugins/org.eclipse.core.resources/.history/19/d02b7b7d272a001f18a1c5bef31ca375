/*
 * adc.h
 *
 *  Created on: Jun 13, 2024
 *      Author: oemerkara
 */

#ifndef ADC_H_
#define ADC_H_
#include "stm32f446xx.h"

#define ADC1EN      (1U << 8)
#define GPIOAEN     (1U << 0)
#define ANALOG_MODE (2U << 2)
#define ADC_CH1     (1U << 0)

void pa1_adc_init(void);

#endif /* ADC_H_ */

#define PERIPH_BASE     0x40000000UL
#define AHB1PERIPH_BASE (PERIPH_BASE + 0x00020000UL)
#define GPIOA_BASE      (AHB1PERIPH_BASE + 0x0000UL)
#define GPIOA           ((GPIO_TypeDef*) GPIOA_BASE)

typedef struct
{
    __IO uint32_t MODER;
    __IO uint32_t OTYPER;
    __IO uint32_t OSPEEDR;
    __IO uint32_t PUPDR;
    __IO uint32_t IDR;
    __IO uint32_t ODR;
    __IO uint32_t BSRR;
    __IO uint32_t LCKR;
    __IO uint32_t AFR[2];
} GPIO_TypeDef;