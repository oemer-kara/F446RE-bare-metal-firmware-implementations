/**
 * @file systick.h
 * @brief Systick driver header file for STM32F446xx.
 *
 * This file contains the function declarations and macro definitions
 * for the Systick timer configuration and delay functionality.
 *
 * @date Created on: Jun 21, 2024
 * @author oemerkara
 */

#ifndef SYSTICK_H_
#define SYSTICK_H_

#include "stm32f446xx.h"


/**
 * @brief Systick timer load value for 1ms delay.
 *
 * The Systick timer is configured to trigger an interrupt every 1ms.
 * Assuming the system clock is running at 16 MHz, the value 16000 is
 * calculated as follows:
 *
 * Load Value = System Clock Frequency × Desired Delay Time
 * Load Value = 16,000,000 Hz × 0.001 s = 16000
 *
 * This means the Systick timer will count down from 16000 to 0, which takes exactly 1ms.
 */
#define SYSTICK_LOAD_VAL 16000

/**
 * @brief Systick control register enable bit.
 */
#define CTRL_ENABLE (1U<<0)

/**
 * @brief Systick control register clock source bit.
 */
#define CTRL_CLCKSRC (1U<<2)

/**
 * @brief Systick control register count flag bit.
 */
#define CTRL_COUNTFLAG (1U<<16)

/**
 * @brief Delays the program execution for a specified number of milliseconds.
 *
 * This function configures the Systick timer to generate a delay for the
 * specified number of milliseconds.
 *
 * @param ms Number of milliseconds to delay.
 */
void systick_delay_ms(int ms);

#endif /* SYSTICK_H_ */
