#include <stdio.h>
#include "error.h"
#include "board.h"
#include "gpio.h"
#include "hid_generic.h"

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

        BOARD_DelayTicks(150);
        gpio_setStat0(1);
        gpio_setStat1(0);
        BOARD_DelayTicks(500);
        gpio_setStat0(0);
        gpio_setStat1(1);
    }
}