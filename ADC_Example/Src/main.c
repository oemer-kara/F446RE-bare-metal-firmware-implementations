/**
 * @brief Testing the ADC conversion.
 *
 * To verify the functionality of the ADC conversion:
 * - Connect ADC channel A1 to GND and check `g_sensor_value`.
 *   - You should observe values close to 0.
 * - Connect ADC channel A1 to 3.3V and check `g_sensor_value`.
 *   - You should observe values close to 4095.
 *
 * This confirms that the analog-to-digital conversion is working correctly.
 */


#include "uart.h"
#include "adc.h"
#include <stdio.h>

uint32_t g_sensor_value; /**< Global variable to store the sensor value */

/**
 * @brief Main function.
 *
 * This is the entry point of the program. It initializes UART2 for communication
 * and the ADC for reading sensor values. The program continuously starts ADC conversion,
 * reads the sensor value, and prints it to the UART.
 *
 * @return int This function does not return.
 */
int main(void)
{
    // Initialize UART2 for transmission and reception
    uart2_txrx_init();
    // Initialize ADC on PA1
    pa1_adc_init();

    while (1)
    {
        // Start ADC conversion
        start_conversion();
        // Read the sensor value from ADC
        g_sensor_value = adc_read();
        // Print the sensor value to UART
        printf("Sensor Value: %d \n\r", (int) g_sensor_value);
    }
}
