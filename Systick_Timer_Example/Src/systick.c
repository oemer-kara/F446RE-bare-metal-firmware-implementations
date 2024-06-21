/*
 * systick.c
 *
 *  Created on: Jun 21, 2024
 *      Author: oemerkara
 */

#include "systick.h"


/*
 * @brief Delays the program execution for a specified number of milliseconds.
 *
 * This function configures the Systick timer to generate a delay for the
 * specified number of milliseconds.
 *
 * @param delay_in_ms Number of milliseconds to delay.
 */
void systick_delay_ms(int delay_in_ms)
{
    // Configure systick
    SysTick->LOAD = SYSTICK_LOAD_VAL;

    // Clear systick current value register
    SysTick->VAL = 0;

    // Enable systick and select internal clock source
    SysTick->CTRL = CTRL_ENABLE | CTRL_CLCKSRC;

    for(int i = 0; i < delay_in_ms; ++i){
        // Wait until the COUNTFLAG is set
        while((SysTick->CTRL & CTRL_COUNTFLAG) == 0){}
    }

    // Disable systick
    SysTick->CTRL = 0;
}


