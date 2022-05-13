#include <stdio.h>
#include "error.h"
#include "board.h"
#include "fsl_debug_console.h"
#include "hid_generic.h"
#include "fsl_gpio.h"
#include "pin_mux.h"

uint8_t rx_buffer[1024] = {0x00};
uint8_t tx_buffer[1024] = {0x00};

void main(void) {
    // Initialze the board peripherals
    BOARD_Init();

    // Other init code
    USB_DeviceApplicationInit(tx_buffer, rx_buffer);

    // Start running the application code
    while(1) {
        // tx_buffer[0] += 1;

        BOARD_DelayTicks(250);
        GPIO_PinWrite(GPIO, BOARD_LED_STAT0_GPIO_PORT, BOARD_LED_STAT0_GPIO_PIN, 1);
        GPIO_PinWrite(GPIO, BOARD_LED_STAT1_GPIO_PORT, BOARD_LED_STAT1_GPIO_PIN, 0);
        BOARD_DelayTicks(250);
        GPIO_PinWrite(GPIO, BOARD_LED_STAT0_GPIO_PORT, BOARD_LED_STAT0_GPIO_PIN, 0);
        GPIO_PinWrite(GPIO, BOARD_LED_STAT1_GPIO_PORT, BOARD_LED_STAT1_GPIO_PIN, 1);
    }
}