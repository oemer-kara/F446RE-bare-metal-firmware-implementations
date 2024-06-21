#include "uart.h"
#include "adc.h"
#include "systick.h"
#include <stdio.h>


#define GPIOA_5 	  (1U<<5)
#define LED 		  GPIOA_5

int main(void)
{
	RCC->AHB1ENR |= GPIOA_EN;
	GPIOA->MODER |= (1U<<10);
	GPIOA->MODER &= ~(1U<<11);

	uart2_txrx_init();

	printf("Start.\n\r");
    while (1)
    {
    	GPIOA->ODR ^= LED;
    	systick_delay_ms(1000);
    	printf("A second passed. \n\r");
    }
}
