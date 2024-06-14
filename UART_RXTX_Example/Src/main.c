
#include "uart.h"
#include <stdio.h>
#include <time.h>


#define GPIOA_5 (1U<<5)
#define LED_PIN GPIOA_5

char key;

int main(void)
{

	RCC->AHB1ENR |=  GPIOA_EN;
	GPIOA->MODER |=  (1U << 10);
	GPIOA->MODER &= ~(1U<<11);

	uart2_txrx_init( );

    while(1)
    {
        key = uart2_read();
        if(key == '1'){
        	GPIOA->ODR |= LED_PIN;
        }else{
        	GPIOA->ODR &= ~LED_PIN;
        }
    }
}