/**
 * @brief Testing UART communication with RealTerm.
 *
 * To verify UART communication:
 * - Open RealTerm and set the baudrate to 115200.
 * - Send characters through RealTerm's terminal.
 *   - If you send '1', the LED should turn on.
 *   - Otherwise, the LED should turn off.
 *
 * This tests the functionality of UART communication with external software.
 */


#include "uart.h"

#define GPIOA_5 (1U<<5) /**< GPIOA Pin 5 */
#define LED_PIN GPIOA_5 /**< LED Pin (GPIOA Pin 5) */


char key; /**< Variable to store received key */

int main(void)
{
    // Enable clock access to GPIOA
    RCC->AHB1ENR |= GPIOA_EN;
    // Set PA5 mode to output
    GPIOA->MODER |= (1U << 10);
    GPIOA->MODER &= ~(1U << 11);

    // Initialize UART2 for transmission and reception
    uart2_txrx_init();

    while (1)
    {
        // Read a character from UART2
        key = uart2_read();
        // Write a character to terminal
        uart2_write(key);
    }
}
