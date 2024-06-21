/*
 * uart.c
 *
 *  Created on: Jun 13, 2024
 *      Author: oemerkara
 */

#include "uart.h"

/**
 * @brief Sends a character via UART.
 *
 * This function writes a character to the UART transmit data register
 * using the uart2_write function.
 *
 * @param ch The character to be transmitted.
 * @return int The transmitted character.
 */
int __io_putchar(int ch)
{
    uart2_write(ch);
    return ch;
}

/**
 * @brief Computes the UART baud rate setting.
 *
 * This function calculates the value to be set in the UART baud rate register
 * based on the peripheral clock and the desired baud rate.
 *
 * @param peripheral_clock The clock frequency of the UART peripheral.
 * @param baud_rate The desired baud rate.
 * @return uint16_t The computed baud rate setting.
 */
uint16_t compute_uart_baud_rate(uint32_t peripheral_clock, uint32_t baud_rate)
{
    return (peripheral_clock + (baud_rate / 2U)) / baud_rate;
}

/**
 * @brief Sets the UART baud rate.
 *
 * This function sets the baud rate of the specified UART peripheral.
 *
 * @param usart_tx The UART peripheral to configure.
 * @param peripheral_clock The clock frequency of the UART peripheral.
 * @param baud_rate The desired baud rate.
 */
void uart_set_baud_rate(USART_TypeDef* usart_tx, uint32_t peripheral_clock, uint32_t baud_rate)
{
    usart_tx->BRR = compute_uart_baud_rate(peripheral_clock, baud_rate);
}

/**
 * @brief Initializes UART2 for transmission and reception.
 *
 * This function configures the necessary GPIO pins and UART2 settings
 * for both transmitting and receiving data.
 *
 * Steps:
 * - Enables clock access to GPIOA.
 * - Sets PA2 and PA3 to alternate function mode for UART.
 * - Configures the alternate function type to UART_TX and UART_RX.
 * - Enables clock access to UART2.
 * - Configures the UART baud rate.
 * - Sets the transfer direction to transmit and receive.
 * - Enables the UART module.
 */
void uart2_txrx_init(void)
{
    // Enable Clock access to GPIOA
    RCC->AHB1ENR |= GPIOA_EN;

    // Set PA2 Mode to Alternate Function Mode
    GPIOA->MODER &= ~(3U << 4);     // Clear bits 4 and 5
    GPIOA->MODER |= (2U << 4);      // Set bits 4 and 5 to 10 (Alternate Function)

    // Set PA2 Alternate Function type to UART_TX (AF07)
    GPIOA->AFR[0] &= ~(0xF << 8);     // Clear bits 8-11
    GPIOA->AFR[0] |= (7U << 8);       // Set bits 8-11 to 0111 (AF7 for USART2)

    GPIOA->MODER &= ~(3U << 6); // Clear bits 6-7
    GPIOA->MODER |= (2U << 6);  // Set bits 6-7 to 10 (Alternate Function)

    // Set PA3 Alternate Function type to UART_RX (AF07)
    GPIOA->AFR[0] &= ~(0xF << 12);
    GPIOA->AFR[0] |= (7U << 12);

    // Enable clock access to UART2
    RCC->APB1ENR |= USART2_EN;

    // Configure UART Baudrate
    uart_set_baud_rate(USART2, APB1_CLK, UART_BAUDRATE);

    // Configure transfer direction
    USART2->CR1 = (CR1_TE | CR1_RE);

    // Enable the UART module
    USART2->CR1 |= CR1_UE;
}

/**
 * @brief Reads a character from UART2.
 *
 * This function waits until the receive data register is not empty,
 * then reads and returns the character from the UART2 data register.
 *
 * @return char The received character.
 */
char uart2_read(void)
{
    // Make sure the receive data register is not empty
    while(!(USART2->SR & SR_RXNE)) {}
    return USART2->DR;
}

/**
 * @brief Sends a character via UART2.
 *
 * This function waits until the transmit data register is empty,
 * then writes the character to the UART2 data register.
 *
 * @param ch The character to be transmitted.
 */
void uart2_write(int ch)
{
    // Make sure the transmit data register is empty
    while(!(USART2->SR & SR_TXE)) {}
    // Write to transmit data register
    USART2->DR = (ch & 0xFF);
}