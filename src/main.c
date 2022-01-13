#include <stdio.h>
#include "error.h"
#include "board.h"
#include "fsl_debug_console.h"
#include "hid_generic.h"

void main(void) {
    // Initialze the board peripherals
    BOARD_Init();

    // Other init code
    USB_DeviceApplicationInit();

    // Start running the application code
    while(1) {
        BOARD_DelayTicks(1000);
        PRINTF("Hello world!\n");
    }
}