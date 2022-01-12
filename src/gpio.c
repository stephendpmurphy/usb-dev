#include <stdint.h>
#include <stdbool.h>
#include "gpio.h"
#include "board.h"
#include "pin_mux.h"

void gpio_setPowerLED(bool val) {
    if( val ) {
        GPIO_PortClear(GPIO, BOARD_LED_PWR_GPIO_PORT, 1u << BOARD_LED_PWR_GPIO_PIN);
    }
    else {
        GPIO_PortSet(GPIO, BOARD_LED_PWR_GPIO_PORT, 1u << BOARD_LED_PWR_GPIO_PIN);
    }
}

void gpio_setCommLED(bool val) {
    if( val ) {
        GPIO_PortClear(GPIO, BOARD_LED_COMM_GPIO_PORT, 1u << BOARD_LED_COMM_GPIO_PIN);
    }
    else {
        GPIO_PortSet(GPIO, BOARD_LED_COMM_GPIO_PORT, 1u << BOARD_LED_COMM_GPIO_PIN);
    }
}

void gpio_setStatusLED(bool val) {
    if( val ) {
        GPIO_PortClear(GPIO, BOARD_LED_STATUS_GPIO_PORT, 1u << BOARD_LED_STATUS_GPIO_PIN);
    }
    else {
        GPIO_PortSet(GPIO, BOARD_LED_STATUS_GPIO_PORT, 1u << BOARD_LED_STATUS_GPIO_PIN);
    }
}

void gpio_setMilliAmpEn(bool val) {
    if( val ) {
        GPIO_PortClear(GPIO, BOARD_mA_nEN_GPIO_PORT, 1u << BOARD_mA_nEN_GPIO_PIN);
    }
    else {
        GPIO_PortSet(GPIO, BOARD_mA_nEN_GPIO_PORT, 1u << BOARD_mA_nEN_GPIO_PIN);
    }
}

void gpio_setMicroAmpEn(bool val) {
    if( val ) {
        GPIO_PortClear(GPIO, BOARD_uA_nEN_GPIO_PORT, 1u << BOARD_uA_nEN_GPIO_PIN);
    }
    else {
        GPIO_PortSet(GPIO, BOARD_uA_nEN_GPIO_PORT, 1u << BOARD_uA_nEN_GPIO_PIN);
    }
}

void gpio_setNanoAmpEn(bool val) {
    if( val ) {
        GPIO_PortClear(GPIO, BOARD_nA_nEN_GPIO_PORT, 1u << BOARD_nA_nEN_GPIO_PIN);
    }
    else {
        GPIO_PortSet(GPIO, BOARD_nA_nEN_GPIO_PORT, 1u << BOARD_nA_nEN_GPIO_PIN);
    }
}