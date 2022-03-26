#include <stdio.h>
#include "error.h"
#include "board.h"
#include "fsl_debug_console.h"
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
        BOARD_DelayTicks(1);
        tx_buffer[0] += 1;
    }
}