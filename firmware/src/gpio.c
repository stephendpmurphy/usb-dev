#include <stdint.h>
#include <stdbool.h>
#include "gpio.h"
#include "board.h"
#include "pin_mux.h"
#include "fsl_gpio.h"

void gpio_setStat0(bool val) {
    if( val ) {
        GPIO_PortClear(GPIO, BOARD_LED_STAT0_GPIO_PORT, 1u << BOARD_LED_STAT0_GPIO_PIN);
    }
    else {
        GPIO_PortSet(GPIO, BOARD_LED_STAT0_GPIO_PORT, 1u << BOARD_LED_STAT0_GPIO_PIN);
    }
}

void gpio_setStat1(bool val) {
    if( val ) {
        GPIO_PortClear(GPIO, BOARD_LED_STAT1_GPIO_PORT, 1u << BOARD_LED_STAT1_GPIO_PIN);
    }
    else {
        GPIO_PortSet(GPIO, BOARD_LED_STAT1_GPIO_PORT, 1u << BOARD_LED_STAT1_GPIO_PIN);
    }
}